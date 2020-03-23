#include <Arduino.h>
#include <WiFi.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>
AsyncWebServer server(80);

const char* ssid = "Home";
const char* password = "narzieagle1992@#$%";

void setup() {
  // put your setup code here, to run once:
  
   Serial.begin(115200);
    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    if (WiFi.waitForConnectResult() != WL_CONNECTED) {
        Serial.printf("WiFi Failed!\n");
        return;
    }

    Serial.print("IP Address: ");
    Serial.println(WiFi.localIP());

   

    server.begin();

    server.on("/", HTTP_GET, [](AsyncWebServerRequest *request){
        request->send(200, "text/plain", "Lwin Moe is genius :p");
    });
    
}

void loop() {
  // put your main code here, to run repeatedly:
  
}
