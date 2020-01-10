//writing eeprom
void writeEEPROM(String username,String password,String ssid,String ssidpass)
{

  int sAddr = 0;
  //writing username
  for(int i=10; i<10+readIndex("username"); i++){
    EEPROM.write(i,username[sAddr]); 
    sAddr++;
  }
  sAddr = 0;
  //writing password
  for(int i=30; i<30+readIndex("password") ;i++){
    EEPROM.write(i,password[sAddr]);
    sAddr++;
  }
  sAddr = 0;
  //writing ssid
  for(int i=50; i<50+readIndex("ssid") ;i++){
    EEPROM.write(i,ssid[sAddr]);
    sAddr++;
  }
  sAddr = 0;
  //writing ssidpass
  for(int i=70; i<70+readIndex("ssidoass") ;i++){
    EEPROM.write(i,ssidpass[sAddr]);
    sAddr++;
  }
  EEPROM.commit();
}

String readEEPROM(String type)
{

   String text = "";
   int start = 0;
 
    if(type.equals("username"))
    {
        start = 10;
    }else if(type.equals("password"))
    {
        start = 30;
    }
    else if(type.equals("ssid"))
    {
         start = 50;
    }
    else if(type.equals("ssidpass"))
    {
         start = 70;
    }
  
     for(int i=start;i<start+readIndex(type);i++) 
     {
          text = text + char(EEPROM.read(i));    
      }  
  
      return text;
}

void writeIndex(String type,int data){
  
    if(type.equals("username"))
    {
        EEPROM.write(0,data);
    }else if(type.equals("password"))
    {
        EEPROM.write(1,data);
    }
    else if(type.equals("ssid"))
    {
         EEPROM.write(2,data);
    }
    else if(type.equals("ssidpass"))
    {
         EEPROM.write(3,data);
    }
 
}

int readIndex(String type)
{    int idx ;
     if(type.equals("username"))
    {
        idx = 0;
    }else if(type.equals("password"))
    {
        idx = 1;
    }
    else if(type.equals("ssid"))
    {
         idx = 2;
    }
    else if(type.equals("ssidpass"))
    {
         idx = 3;
    }
    
    return EEPROM.read(idx);
}

