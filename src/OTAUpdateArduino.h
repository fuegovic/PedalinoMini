/*
  (c) 2018-2025 alf45star
  https://github.com/alf45tar/PedalinoMini

  This file is part of PedalinoMini.

  You should have received a copy of the GNU General Public License
  along with PedalinoMini. If not, see <http://www.gnu.org/licenses/>.

  Modifications by Fuegovic, 2025.
*/

#if !defined(ARDUINOOTA) || defined(NOWIFI)
#define ota_begin(...)
#define ota_handle(...)
#define ota_end(...)
#else

#include <WiFi.h>
#include <ESPmDNS.h>
#include <ArduinoOTA.h>

void ota_begin(const char *hostname) {

  ArduinoOTA.setHostname(hostname);
  ArduinoOTA.begin();

  ArduinoOTA.onStart([]() {
      firmwareUpdate = PED_UPDATE_ARDUINO_OTA;
#ifdef WEBSOCKET
    webSocket.enable(false);
    webSocket.closeAll();
#endif
    display.clear();
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
    display.drawString(display.getWidth() / 2, display.getHeight() / 2 - 10, "OTA Update");
    display.display();

    fill_solid(fastleds, LEDS, CRGB::Black);
    FastLED.show();
  });

  ArduinoOTA.onProgress([](unsigned int progress, unsigned int total) {
    display.drawProgressBar(4, 32, 120, 8, progress / (total / 100) );
    display.display();
    byte ledProgress = (progress / (total / (LEDS * 100))) / 100;
    fill_solid(fastleds, ledProgress + 1, swap_rgb_order(CRGB::Red, rgbOrder));
    byte ledDim = (progress / (total / (LEDS * 100))) % 100;
    fastleds[ledProgress].nscale8(ledDim);
    FastLED.show();
  });

  ArduinoOTA.onEnd([]() {
    display.clear();
    display.setFont(ArialMT_Plain_10);
    display.setTextAlignment(TEXT_ALIGN_CENTER_BOTH);
    display.drawString(display.getWidth() / 2, display.getHeight() / 2, "Restart");
    display.display();
    fill_solid(fastleds, LEDS, swap_rgb_order(CRGB::Green, rgbOrder));
    FastLED.show();
  });

  DPRINT("OTA update started\n");
}

inline void ota_handle() {
  ArduinoOTA.handle();
}

inline void ota_end() {
  ArduinoOTA.End();
}

#endif  // NOWIFI