const e = (e, o, t, n) => {
  n = n || {};
  const r = new CustomEvent(o, {
    bubbles: void 0 === n.bubbles || n.bubbles,
    cancelable: Boolean(n.cancelable),
    composed: void 0 === n.composed || n.composed,
    detail: t,
  });
  e.dispatchEvent(r);
};
class o extends HTMLElement {
  connectedCallback() {
    if (this.renderRoot) return;
    if (
      ((this.renderRoot = this.attachShadow({ mode: "open" })),
      !o.isSupported || !o.isAllowed)
    )
      return (
        this.toggleAttribute("not-supported", !0),
        void (this.renderRoot.innerHTML = o.isAllowed
          ? "<slot name='unsupported'>Your browser does not support serial provisioning. Use Google Chrome or Microsoft Edge.</slot>"
          : "<slot name='not-allowed'>You can only use Improv on HTTPS sites or localhost.</slot>")
      );
    this.toggleAttribute("supported", !0);
    const t = document.createElement("slot");
    t.name = "activate";
    const n = document.createElement("button");
    if (
      ((n.innerText = "Connect device to Wi-Fi"),
      t.append(n),
      t.addEventListener("click", async (o) => {
        o.preventDefault(),
          (async (o) => {
            let t;
            import("./serial-provision-dialog-8dcc4267.js");
            try {
              t = await navigator.serial.requestPort();
            } catch (e) {
              if ("NotFoundError" === e.name) return;
              return void alert(`Error: ${e.message}`);
            }
            if (!t) return;
            await t.open({ baudRate: 115200 });
            const n = document.createElement(
              "improv-wifi-serial-provision-dialog",
            );
            (n.port = t),
              n.addEventListener(
                "closed",
                async (n) => {
                  await t.close(), e(o, "closed", n.detail);
                },
                { once: !0 },
              ),
              document.body.appendChild(n);
          })(this);
      }),
      "adoptedStyleSheets" in Document.prototype &&
        "replaceSync" in CSSStyleSheet.prototype)
    ) {
      const e = new CSSStyleSheet();
      e.replaceSync(o.style), (this.renderRoot.adoptedStyleSheets = [e]);
    } else {
      const e = document.createElement("style");
      (e.innerText = o.style), this.renderRoot.append(e);
    }
    this.renderRoot.append(t);
  }
}
(o.isSupported = "serial" in navigator),
  (o.isAllowed = window.isSecureContext),
  (o.style =
    '\n  button {\n    position: relative;\n    cursor: pointer;\n    font-size: 14px;\n    padding: 8px 28px;\n    color: var(--improv-on-primary-color, #fff);\n    background-color: var(--improv-primary-color, #03a9f4);\n    border: none;\n    border-radius: 4px;\n    box-shadow: 0 2px 2px 0 rgba(0,0,0,.14), 0 3px 1px -2px rgba(0,0,0,.12), 0 1px 5px 0 rgba(0,0,0,.2);\n  }\n  button::before {\n    content: " ";\n    position: absolute;\n    top: 0;\n    bottom: 0;\n    left: 0;\n    right: 0;\n    opacity: 0.2;\n    border-radius: 4px;\n  }\n  button:hover {\n    box-shadow: 0 4px 8px 0 rgba(0,0,0,.14), 0 1px 7px 0 rgba(0,0,0,.12), 0 3px 1px -1px rgba(0,0,0,.2);\n  }\n  button:hover::before {\n    background-color: rgba(255,255,255,.8);\n  }\n  button:focus {\n    outline: none;\n  }\n  button:focus::before {\n    background-color: white;\n  }\n  button:active::before {\n    background-color: grey;\n  }\n'),
  customElements.define("improv-wifi-serial-launch-button", o);
export { e as f };
