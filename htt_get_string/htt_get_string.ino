#include <WiFi.h>
#include <HTTPClient.h>
 
const char* ssid = "Home";
const char* password =  "narzieagle1992@#$%";
 
void setup() {
 
  Serial.begin(115200);
  delay(4000);
  WiFi.begin(ssid, password);
 
  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi..");
  }
 
  Serial.println("Connected to the WiFi network");
 
}
 
void loop() {
 
  if ((WiFi.status() == WL_CONNECTED)) { //Check the current connection status
 
    HTTPClient http;
 
    http.begin("http://ppk.pythonanywhere.com/iot"); 
    int httpCode = http.GET();                                        
 
    if (httpCode > 0) { 
 
        String payload = http.getString();
        Serial.println(httpCode);
        Serial.println(payload);
        Serial.println("Saving to SPIFFS....");
        
       
      }
 
    else {
      Serial.println("Error on HTTP request");
    }
 
    http.end(); 
  }

  
 
  delay(10000);
 
}
