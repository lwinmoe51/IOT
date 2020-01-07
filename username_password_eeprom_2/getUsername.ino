String getUsername(){
  String usernameInEeprom = "";
  for(int i=0;i<length_arr[0];i++) 
  {
    usernameInEeprom = usernameInEeprom + char(EEPROM.read(i));    
  }  
  return usernameInEeprom;
}
