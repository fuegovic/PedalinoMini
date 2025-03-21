import { ERROR_MSGS, ImprovSerialCurrentState, ImprovSerialMessageType, PortNotReady, SERIAL_PACKET_HEADER, } from "./const.js";
import { sleep } from "./util/sleep";
import { hexFormatter } from "./util/hex-formatter";
export class ImprovSerial extends EventTarget {
    constructor(port, logger) {
        super();
        this.port = port;
        this.logger = logger;
        this.error = 0 /* ImprovSerialErrorState.NO_ERROR */;
        if (port.readable === null) {
            throw new Error("Port is not readable");
        }
        if (port.writable === null) {
            throw new Error("Port is not writable");
        }
    }
    /**
     * Detect Improv Serial, fetch the state and return the next URL if provisioned.
     * @param timeout Timeout in ms to wait for the device to respond. Default to 1000ms.
     */
    async initialize(timeout = 1000) {
        this.logger.log("Initializing Improv Serial");
        this._processInput();
        // To give the input processing time to start.
        await sleep(1000);
        if (this._reader === undefined) {
            throw new PortNotReady();
        }
        try {
            await new Promise(async (resolve, reject) => {
                setTimeout(() => reject(new Error("Improv Wi-Fi Serial not detected")), timeout);
                await this.requestCurrentState();
                resolve(undefined);
            });
            await this.requestInfo();
        }
        catch (err) {
            await this.close();
            throw err;
        }
        return this.info;
    }
    async close() {
        if (!this._reader) {
            return;
        }
        await new Promise((resolve) => {
            this._reader.cancel();
            this.addEventListener("disconnect", resolve, { once: true });
        });
    }
    /**
     * This command will trigger at least one packet,
     * the Current State and if already provisioned,
     * the same response you would get if device provisioning
     * was successful (see below).
     */
    async requestCurrentState() {
        // Request current state and wait for 5s
        let rpcResult;
        try {
            await new Promise(async (resolve, reject) => {
                this.addEventListener("state-changed", resolve, { once: true });
                const cleanupAndReject = (err) => {
                    this.removeEventListener("state-changed", resolve);
                    reject(err);
                };
                rpcResult = this._sendRPCWithResponse(2 /* ImprovSerialRPCCommand.REQUEST_CURRENT_STATE */, []);
                rpcResult.catch(cleanupAndReject);
            });
        }
        catch (err) {
            this._rpcFeedback = undefined;
            throw new Error(`Error fetching current state: ${err}`);
        }
        // Only if we are provisioned will we get an rpc result
        if (this.state !== ImprovSerialCurrentState.PROVISIONED) {
            this._rpcFeedback = undefined;
            return;
        }
        const data = await rpcResult;
        this.nextUrl = data[0];
    }
    async requestInfo(timeout) {
        const response = await this._sendRPCWithResponse(3 /* ImprovSerialRPCCommand.REQUEST_INFO */, [], timeout);
        this.info = {
            firmware: response[0],
            version: response[1],
            name: response[3],
            chipFamily: response[2],
        };
    }
    async provision(ssid, password, timeout) {
        const encoder = new TextEncoder();
        const ssidEncoded = encoder.encode(ssid);
        const pwEncoded = encoder.encode(password);
        const data = [
            ssidEncoded.length,
            ...ssidEncoded,
            pwEncoded.length,
            ...pwEncoded,
        ];
        const response = await this._sendRPCWithResponse(1 /* ImprovSerialRPCCommand.SEND_WIFI_SETTINGS */, data, timeout);
        this.nextUrl = response[0];
    }
    async scan() {
        const results = await this._sendRPCWithMultipleResponses(4 /* ImprovSerialRPCCommand.REQUEST_WIFI_NETWORKS */, []);
        const ssids = results.map(([name, rssi, secured]) => ({
            name,
            rssi: parseInt(rssi),
            secured: secured === "YES",
        }));
        ssids.sort((a, b) => a.name.toLocaleLowerCase().localeCompare(b.name.toLocaleLowerCase()));
        return ssids;
    }
    _sendRPC(command, data) {
        this.writePacketToStream(ImprovSerialMessageType.RPC, [
            command,
            data.length,
            ...data,
        ]);
    }
    async _sendRPCWithResponse(command, data, timeout) {
        // Commands that receive feedback will finish when either
        // the state changes or the error code becomes not 0.
        if (this._rpcFeedback) {
            throw new Error("Only 1 RPC command that requires feedback can be active");
        }
        return await this._awaitRPCResultWithTimeout(new Promise((resolve, reject) => {
            this._rpcFeedback = { command, resolve, reject };
            this._sendRPC(command, data);
        }), timeout);
    }
    async _sendRPCWithMultipleResponses(command, data, timeout) {
        // Commands that receive multiple feedbacks will finish when either
        // the state changes or the error code becomes not 0.
        if (this._rpcFeedback) {
            throw new Error("Only 1 RPC command that requires feedback can be active");
        }
        return await this._awaitRPCResultWithTimeout(new Promise((resolve, reject) => {
            this._rpcFeedback = {
                command,
                resolve,
                reject,
                receivedData: [],
            };
            this._sendRPC(command, data);
        }), timeout);
    }
    async _awaitRPCResultWithTimeout(sendRPCPromise, timeout) {
        if (!timeout) {
            return await sendRPCPromise;
        }
        return await new Promise((resolve, reject) => {
            const timeoutRPC = setTimeout(() => this._setError(254 /* ImprovSerialErrorState.TIMEOUT */), timeout);
            sendRPCPromise.finally(() => clearTimeout(timeoutRPC));
            sendRPCPromise.then(resolve, reject);
        });
    }
    async _processInput() {
        // read the data from serial port.
        // current state, error state, rpc result
        this.logger.debug("Starting read loop");
        this._reader = this.port.readable.getReader();
        try {
            let line = [];
            // undefined = not sure if improv packet
            let isImprov;
            // length of improv bytes that we expect
            let improvLength = 0;
            while (true) {
                const { value, done } = await this._reader.read();
                if (done) {
                    break;
                }
                if (!value || value.length === 0) {
                    continue;
                }
                for (const byte of value) {
                    if (isImprov === false) {
                        // When it wasn't an improv line, discard everything unti we find new line char
                        if (byte === 10) {
                            isImprov = undefined;
                        }
                        continue;
                    }
                    if (isImprov === true) {
                        line.push(byte);
                        if (line.length === improvLength) {
                            this._handleIncomingPacket(line);
                            isImprov = undefined;
                            line = [];
                        }
                        continue;
                    }
                    if (byte === 10) {
                        line = [];
                        continue;
                    }
                    line.push(byte);
                    if (line.length !== 9) {
                        continue;
                    }
                    // Check if it's improv
                    isImprov = String.fromCharCode(...line.slice(0, 6)) === "IMPROV";
                    if (!isImprov) {
                        line = [];
                        continue;
                    }
                    // Format:
                    // I M P R O V <VERSION> <TYPE> <LENGTH> <DATA> <CHECKSUM>
                    // Once we have 9 bytes, we can check if it's an improv packet
                    // and extract how much more we need to fetch.
                    const packetLength = line[8];
                    improvLength = 9 + packetLength + 1; // header + data length + checksum
                }
            }
        }
        catch (err) {
            this.logger.error("Error while reading serial port", err);
        }
        finally {
            this._reader.releaseLock();
            this._reader = undefined;
        }
        this.logger.debug("Finished read loop");
        this.dispatchEvent(new Event("disconnect"));
    }
    _handleIncomingPacket(line) {
        const payload = line.slice(6);
        const version = payload[0];
        const packetType = payload[1];
        const packetLength = payload[2];
        const data = payload.slice(3, 3 + packetLength);
        this.logger.debug("PROCESS", {
            version,
            packetType,
            packetLength,
            data: hexFormatter(data),
        });
        if (version !== 1) {
            this.logger.error("Received unsupported version", version);
            return;
        }
        // Verify checksum
        let packetChecksum = payload[3 + packetLength];
        let calculatedChecksum = 0;
        for (let i = 0; i < line.length - 1; i++) {
            calculatedChecksum += line[i];
        }
        calculatedChecksum = calculatedChecksum & 0xff;
        if (calculatedChecksum !== packetChecksum) {
            this.logger.error(`Received invalid checksum ${packetChecksum}. Expected ${calculatedChecksum}`);
            return;
        }
        if (packetType === ImprovSerialMessageType.CURRENT_STATE) {
            this.state = data[0];
            this.dispatchEvent(new CustomEvent("state-changed", {
                detail: this.state,
            }));
        }
        else if (packetType === ImprovSerialMessageType.ERROR_STATE) {
            this._setError(data[0]);
        }
        else if (packetType === ImprovSerialMessageType.RPC_RESULT) {
            if (!this._rpcFeedback) {
                this.logger.error("Received result while not waiting for one");
                return;
            }
            const rpcCommand = data[0];
            if (rpcCommand !== this._rpcFeedback.command) {
                this.logger.error(`Received result for command ${rpcCommand} but expected ${this._rpcFeedback.command}`);
                return;
            }
            // Chop off rpc command and checksum
            const result = [];
            const totalLength = data[1];
            let idx = 2;
            while (idx < 2 + totalLength) {
                result.push(String.fromCodePoint(...data.slice(idx + 1, idx + data[idx] + 1)));
                idx += data[idx] + 1;
            }
            if ("receivedData" in this._rpcFeedback) {
                if (result.length > 0) {
                    this._rpcFeedback.receivedData.push(result);
                }
                else {
                    // Result of 0 means we're done.
                    this._rpcFeedback.resolve(this._rpcFeedback.receivedData);
                    this._rpcFeedback = undefined;
                }
            }
            else {
                this._rpcFeedback.resolve(result);
                this._rpcFeedback = undefined;
            }
        }
        else {
            this.logger.error("Unable to handle packet", payload);
        }
    }
    /**
     * Add header + checksum and write packet to stream
     */
    async writePacketToStream(type, data) {
        const payload = new Uint8Array([
            ...SERIAL_PACKET_HEADER,
            type,
            data.length,
            ...data,
            0,
            0, // Will be newline
        ]);
        // Calculate checksum
        payload[payload.length - 2] =
            payload.reduce((sum, cur) => sum + cur, 0) & 0xff;
        payload[payload.length - 1] = 10; // Newline
        this.logger.debug("Writing to stream:", hexFormatter(new Array(...payload)));
        const writer = this.port.writable.getWriter();
        await writer.write(payload);
        try {
            writer.releaseLock();
        }
        catch (err) {
            console.error("Ignoring release lock error", err);
        }
    }
    // Error is either received from device or is a timeout
    _setError(error) {
        this.error = error;
        if (error > 0 && this._rpcFeedback) {
            this._rpcFeedback.reject(ERROR_MSGS[error] || `UNKNOWN_ERROR (${error})`);
            this._rpcFeedback = undefined;
        }
        this.dispatchEvent(new CustomEvent("error-changed", {
            detail: this.error,
        }));
    }
}
