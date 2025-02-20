#pragma once

#include <Arduino.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Update.h>
#include <StreamString.h>
#include <FS.h>
#include <SPIFFS.h>
#include <nvs.h>

#include "../Version.h"
#include "../Config.h"
#include "../Controller.h"
#include "../Pedalino.h"

// External declarations for dependencies
extern String wifiSSID;
#ifndef PROFILES
#define PROFILES 3
#endif
#ifndef BANKS
#define BANKS 21
#endif
#ifndef PEDALS
#define PEDALS 16
#endif
#ifndef CONTROLS
#define CONTROLS 36
#endif
#ifndef SEQUENCES
#define SEQUENCES 30
#endif
#ifndef LEDS
#define LEDS 16
#endif

// Boot mode constants
#define PED_BOOT_NORMAL     0
#define PED_BOOT_BLE       1
#define PED_BOOT_WIFI      2
#define PED_BOOT_AP        3
#define PED_BOOT_AP_NO_BLE 4
extern String page;
extern String alert;
extern String alertError;
extern String theme;
extern String uiprofile;
extern String uibank;
extern String uicontrol;
extern String uicontrolpage;
extern String uisequence;
extern bool fullPageCompleted;
extern bool reloadProfile;
extern byte currentProfile;
extern byte bootMode;
extern String sketchSize;
extern String sketchMD5;
extern String getChipId();
extern bool appleMidiConnected;
extern String appleMidiSessionName;
extern bool bleMidiConnected;
extern String host;
extern String ssidSoftAP;
extern float batteryVoltage;
extern unsigned long freeMemory;
extern unsigned long maxAllocation;

// Function declarations
bool trim_page(unsigned int start, unsigned int len, bool lastcall = false);
void get_footer_page();

void get_root_page(unsigned int start, unsigned int len) {

  if (reloadProfile) controller_run();

  page = "";

  page += F("<!doctype html>");
  page += F("<html lang='en' data-bs-theme='dark'>");
  page += F("<head>");
  page += F("<title>PedalinoMini&trade;</title>");
  page += F("<meta charset='utf-8'>");
  page += F(" <meta name='viewport' content='width=device-width, initial-scale=1, shrink-to-fit=no'>");
  if ( theme == "bootstrap" ) {
  #ifdef BOOTSTRAP_LOCAL
    page += F("<link rel='stylesheet' href='/css/bootstrap.min.css' integrity='sha384-QWTKZyjpPEjISv5WaRU9OFeRpok6YctnYmDr5pNlyT2bRjXh0JMhjY6hW+ALEwIH' crossorigin='anonymous'>");
  #else
    page += F("<link href='https://cdn.jsdelivr.net/npm/bootstrap@latest/dist/css/bootstrap.min.css' rel='stylesheet' crossorigin='anonymous'>");
  #endif
  } else {
    page += F("<link href='https://cdn.jsdelivr.net/npm/bootswatch@latest/dist/");
    page += theme;
    page += F("/bootstrap.min.css' rel='stylesheet' crossorigin='anonymous'>");
  }
  page += F("</head>");

  page += F("<body>");

  if (trim_page(start, len)) return;

  page += F("<div class='container-fluid mt-3 mb-3'>");

  page += F("<h4 class='display-4'>Wireless MIDI foot controller</h4>");

  page += F("<div class='row row-cols-1 row-cols-sm-2 row-cols-lg-4'>");

  page += F("<div class='col'>");
  page += F("<h3>Product</h3>");
  page += F("<dt>Model</dt><dd>");
  page += MODEL;
  page += F("</dd>");
  page += F("<dt>Profiles</dt><dd>");
  page += PROFILES;
  page += F("</dd>");
  page += F("<dt>Banks</dt><dd>");
  page += BANKS;
  page += F("</dd>");
  page += F("<dt>Pedals</dt><dd>");
  page += PEDALS;
  page += F("</dd>");
  page += F("<dt>Controls</dt><dd>");
  page += CONTROLS;
  page += F("</dd>");
  page += F("<dt>Sequences</dt><dd>");
  page += SEQUENCES;
  page += F("</dd>");
  page += F("<dt>Leds</dt><dd>");
  page += LEDS;
  page += F("</dd>");
  page += F("<dt>Boot Mode</dt><dd>");
  switch (bootMode) {
    case PED_BOOT_NORMAL:
      page += F("Normal");
      break;
    case PED_BOOT_BLE:
      page += F("BLE only");
      break;
    case PED_BOOT_WIFI:
      page += F("WiFi only");
      break;
    case PED_BOOT_AP:
      page += F("Access Point and BLE");
      break;
    case PED_BOOT_AP_NO_BLE:
      page += F("Access Point without BLE");
      break;
  }
  page += F("</dd>");
  page += F("<dt>PlatformIO ESP32 Platform</dt><dd>");
  page += xstr(ESP32_PLATFORM_VERSION);
  page += F("</dd>");
  page += F("<dt>IDF Version</dt><dd>");
  page += ESP_IDF_VERSION_MAJOR;
  page += F(".");
  page += ESP_IDF_VERSION_MINOR;
  page += F(".");
  page += ESP_IDF_VERSION_PATCH;
  page += F("</dd>");
  page += F("<dt>SDK Version</dt><dd>");
  page += ESP.getSdkVersion();
  page += F("</dd>");
  page += F("<dt>PlatformIO Build Env</dt><dd>");
  page += xstr(PLATFORMIO_ENV);
  page += F("</dd>");

  page += F("<dt>Bootstrap Version</dt><dd><span id='bootstrap-version'></span></dd>");
  page += F("<script>"
            "   document.addEventListener('DOMContentLoaded', function() {"
            "     if (typeof bootstrap !== 'undefined') {"
            "       document.getElementById('bootstrap-version').textContent = bootstrap.Tooltip.VERSION;"
            "     } else {"
            "       document.getElementById('bootstrap-version').textContent = 'Not available';"
            "     }"
            "   });"
            "</script>");

  page += F("<dt>Firmware</dt><dd>");
  page += PEDALINO_VERSION_MAJOR;
  page += F(".");
  page += PEDALINO_VERSION_MINOR;
  page += F(".");
  page += PEDALINO_VERSION_PATCH;
  page += F(" - ");
  page += PEDALINO_VERSION_SUFFIX;
  page += F("</dd>");
  page += F("<dt>Firmware Size</dt><dd>");
  page += sketchSize;
  page += F(" bytes</dd>");
  page += F("<dt>Firmware Hash</dt><dd>");
  page += sketchMD5;
  page += F("</dd>");
  page += F("</div>");
  
  if (trim_page(start, len)) return;

  page += F("<div class='col'>");
  page += F("<h3>Hardware</h3>");
  page += F("<dt>Board</dt><dd>");
  page += ARDUINO_BOARD;
  page += F("</dd>");
  page += F("<dt>Chip</dt><dd>");
  page += ESP.getChipModel();
  page += F("</dd>");
  page += F("<dt>Chip Revision</dt><dd>");
  page += ESP.getChipRevision();
  page += F("</dd>");
  page += F("</dd>");
  page += F("<dt>Chip ID</dt><dd>");
  page += getChipId();
  page += F("</dd>");
  page += F("<dt>CPU Frequency</dt><dd>");
  page += ESP.getCpuFreqMHz();
  page += F(" MHz</dd>");
  page += F("<dt>Flash Chip Frequency</dt><dd>");
  page += ESP.getFlashChipSpeed() / 1000000;
  page += F(" MHz</dd>");
  page += F("<dt>Flash Size</dt><dd>");
  page += ESP.getFlashChipSize() / (1024 * 1024);
  page += F(" MB</dd>");
  page += F("<dt>PSRAM Used/Total</dt><dd>");
  page += (ESP.getPsramSize() - ESP.getFreePsram()) / 1024;
  page += F("/");
  page += ESP.getPsramSize() / 1024;
  page += F(" kB</dd>");
  nvs_stats_t nvs_stats;
  if (nvs_get_stats("nvs", &nvs_stats) == ESP_OK) {
    page += F("<dt>NVS Used/Total</dt><dd>");
    page += nvs_stats.used_entries;
    page += F("/");
    page += nvs_stats.total_entries;
    page += F(" entries</dd>");
  }
  page += F("<dt>SPIFFS Used/Total</dt><dd>");
  page += SPIFFS.usedBytes() / 1024;
  page += F("/");
  page += SPIFFS.totalBytes() / 1024;
  page += F(" kB</dd>");
  page += F("<dt>Free Heap Size (Max Allocation)</dt><dd>");
  page += freeMemory / 1024;
  page += F(" kB (");
  page += maxAllocation / 1024;
  page += F(" kB)</dd>");
#ifdef BATTERY
#ifdef ARDUINO_BPI_LEAF_S3
  page += F("<dt>Battery Voltage</dt><dd>");
  page += String(batteryVoltage / 1000.0, 1);
  page += F(" V ");
  page += F("</dd>");
#else
  page += F("<dt>Input Voltage</dt><dd>");
  page += String(batteryVoltage / 1000.0, 1);
  page += F(" V ");
  page += batteryVoltage > 4300 ? F("plugged") : F("on battery");
  page += F("</dd>");
#endif // ARDUINO_BPI_LEAF_S3
#endif // BATTERY
  page += F("<dt>Uptime</dt><dd>");
  unsigned long sec = (millis() / 1000) % 60;
  unsigned long min = (millis() / 1000 / 60) % 60;
  unsigned long h   = (millis() / 1000 / 60 / 60) % 24;
  unsigned long day = (millis() / 1000 / 60 / 60 / 24);
  if (day > 0) { page += day; page += F("d "); }
  if (h   > 0) { page += h;   page += F("h "); }
  if (min > 0) { page += min; page += F("m "); }
  page += sec;
  page += F("s");
  page += F("</dd>");
  page += F("<dt>Webserver Running On Core</dt><dd>");
  page += xPortGetCoreID();
  page += F("</dd>");
  page += F("</div>");

  if (trim_page(start, len)) return;

  page += F("<div class='col'>");
  if (WiFi.getMode() == WIFI_STA || WiFi.getMode() == WIFI_AP_STA) {
  page += F("<h3>Wireless STA</h3>");
  page += F("<dt>SSID</dt><dd>");
  page += wifiSSID;
  page += F("</dd>");
  page += F("<dt>BSSID</dt><dd>");
  page += WiFi.BSSIDstr();
  page += F("</dd>");
  page += F("<dt>RSSI</dt><dd>");
  page += WiFi.RSSI();
  page += F(" dBm</dd>");
  page += F("<dt>Channel</dt><dd>");
  page += WiFi.channel();
  page += F("</dd>");
  page += F("<dt>Station MAC</dt><dd>");
  page += WiFi.macAddress();
  page += F("</dd>");
  }

  if (WiFi.getMode() == WIFI_AP || WiFi.getMode() == WIFI_AP_STA) {
  page += F("<h3>Wireless AP</h3>");
  page += F("<dt>AP SSID</dt><dd>");
  page += ssidSoftAP;
  page += F("</dd>");
  page += F("<dt>AP MAC Address</dt><dd>");
  page += WiFi.softAPmacAddress();
  page += F("</dd>");
  page += F("<dt>AP IP Address</dt><dd>");
  page += WiFi.softAPIP().toString();
  page += F("</dd>");
  page += F("<dt>Channel</dt><dd>");
  page += WiFi.channel();
  page += F("</dd>");
  page += F("<dt>Hostname</dt><dd>");
  page += WiFi.softAPgetHostname();
  page += F("</dd>");
  page += F("<dt>Connected Stations</dt><dd>");
  page += WiFi.softAPgetStationNum();
  page += F("</dd>");
  }
  page += F("</div>");

  page += F("<div class='col'>");
  page += F("<h3>Network</h3>");
  page += F("<dt>Hostname</dt><dd>");
  page += WiFi.getHostname();
  page += F(".local");
  page += F("</dd>");
  page += F("<dt>IP address</dt><dd>");
  page += WiFi.localIP().toString();
  page += F("</dd>");
  page += F("<dt>Subnet mask</dt><dd>");
  page += WiFi.subnetMask().toString();
  page += F("</dd>");
  page += F("<dt>Gataway IP</dt><dd>");
  page += WiFi.gatewayIP().toString();
  page += F("</dd>");
  page += F("<dt>DNS 1</dt><dd>");
  page += WiFi.dnsIP(0).toString();
  page += F("</dd>");
  page += F("<dt>DNS 2</dt><dd>");
  page += WiFi.dnsIP(1).toString();
  page += F("</dd>");
  page += F("<dt>MIDI Network</dt><dd>");
  if (appleMidiConnected) {
    page += F("Connected to<br>");
    page += appleMidiSessionName;
  }
  else page += F("Disconnected");
  page += F("</dd>");
#ifdef BLE
  page += F("<dt>Bluetooth LE MIDI</dt><dd>");
  if (bleMidiConnected) page += F("Connected");
  else page += F("Disconnected");
  page += F("</dd>");
#endif
  page += F("</div>");

  page += F("</div>");

  get_footer_page();

  if (trim_page(start, len, true)) return;
}

size_t get_root_page_chunked(uint8_t *buffer, size_t maxLen, size_t index) {
  page = "";
  get_root_page(index, maxLen - 1);
  page.getBytes(buffer, maxLen, 0);
  buffer[maxLen-1] = 0; // CWE-126
  size_t byteWritten = strlen((const char *)buffer);
  if (byteWritten == 0) {
    page = "";
    alert = "";
    alertError = "";
    fullPageCompleted = true;
  }
  return byteWritten;
}
