/*If u want to use a OTA for the first time; u don't need to chage this sketch. (except ur wifi SSID and password)
 * Upload this sketch to ur esp32 which u want to program OTA from ur computer directly.(must do)
 * 
 * Now U can add ur custom program into this sketch OTA. 
 * 
 * WARNNING: DON'T delect anything. Just add ur custom code which u want to upload with OTA.
 */
#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

const char* ssid = "test";
const char* password = "1234567890";

void setup() {
  //wifi conneting
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  //if wifi can't connect, reconnecting
  while (WiFi.waitForConnectResult() != WL_CONNECTED) {
    ESP.restart();
  }
  //OTA initializing
  ArduinoOTA.begin();
}

void loop() {
  //OTA one main code line (i don't know detail
  ArduinoOTA.handle();
  //what ever u want to program for esp32
}
