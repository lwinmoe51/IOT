#include <EEPROM.h>

  String username = "admin";
  String password = "adminpass";
  String ssid = "LWIN";
  String ssidpass = "LWINpass";
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  EEPROM.begin(512);

  //get from user


  writeIndex("username",username.length());
    writeIndex("password",password.length());
      writeIndex("ssid",ssid.length());
        writeIndex("ssidpass",ssidpass.length());
  writeEEPROM(username,password,ssid,ssidpass);
  
}


void loop() {
  // put your main code here, to run repeatedly:

  

  Serial.println(readEEPROM("username"));
  Serial.println(readEEPROM("password"));
  Serial.println(readEEPROM("ssid"));
  Serial.println(readEEPROM("ssidpass"));
  Serial.println(readIndex("username"));
  Serial.println(readIndex("password"));
  Serial.println(readIndex("ssid"));
  Serial.println(readIndex("ssidpass"));
  //Serial.println(b);
  delay(2000);
  
}
