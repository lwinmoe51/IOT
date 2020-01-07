String getPassword(){
  String passwordInEeprom = "";
  for(int i=length_arr[0];i<length_arr[0]+length_arr[1];i++) 
  {
    passwordInEeprom = passwordInEeprom + char(EEPROM.read(i));    
  }  
  
  return passwordInEeprom;
}

