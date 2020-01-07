#include <EEPROM.h>
String username = "LWIN MOE";
String password = "1234567890";
int length_arr[2];
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  EEPROM.begin(512);
  writeEEPROM();
  
}

void loop() {
  // put your main code here, to run repeatedly:
  String a = getUsername();
  String b = getPassword();
  //Serial.println(length_arr[0]);
  //Serial.println(length_arr[1]);
  Serial.println(a);
  Serial.println(b);
  delay(2000);
  
}
