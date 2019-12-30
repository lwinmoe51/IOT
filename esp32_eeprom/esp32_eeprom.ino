#include <EEPROM.h>
 
// the current address in the EEPROM (i.e. which byte
// we're going to write to next)
int addr = 0;
 
void setup()
{
  EEPROM.begin(512);  //Initialize EEPROM
  Serial.begin(9600);
 
  // write appropriate byte of the EEPROM.
  // these values will remain there when the board is
  // turned off.
  
  EEPROM.write(addr, 'A');    //Write character A
  addr++;                      //Increment address
  EEPROM.write(addr, 'B');    //Write character A
  addr++;                      //Increment address
  EEPROM.write(addr, 'C');    //Write character A
 
  /*Write string to eeprom
  String www = "www.circuits4you.com";
  for(int i=0;i<www.length();i++) //loop upto string lenght www.length() returns length of string
  {
    EEPROM.write(0x0F+i,www[i]); //Write one by one with starting address of 0x0F
  }*/
  EEPROM.commit();    //Store data to EEPROM

   // read appropriate byte of the EEPROM.  
  Serial.println(""); //Goto next line, as ESP sends some garbage when you reset it  
  Serial.print(char(EEPROM.read(addr)));    //Read from address 0x00
  addr++;                      //Increment address
  Serial.print(char(EEPROM.read(addr)));    //Read from address 0x01
  addr++;                      //Increment address
  Serial.println(char(EEPROM.read(addr)));    //Read from address 0x02
 
  //Read string from eeprom
    
  /*Here we dont know how many bytes to read it is better practice to use some terminating character
  //Lets do it manually www.circuits4you.com  total length is 20 characters
  for(int i=0;i<20;i++) 
  {
    www = www + char(EEPROM.read(0x0F+i)); //Read one by one with starting address of 0x0F    
  }  
 
  Serial.print(www);  //Print the text on serial monitor*/
}

 
void loop()
{
  //We dont have anything in loop as EEPROM writing is done only once
  delay(10);   
}
