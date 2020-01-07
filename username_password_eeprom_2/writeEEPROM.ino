void writeEEPROM(){
  int pAddr = 0;
  setUpUser(username,password,length_arr);
  for(int i=0; i<length_arr[0]; i++){
    EEPROM.write(i,username[i]);
  }
  for(int i=length_arr[0]; i<length_arr[0]+length_arr[1] ;i++){
    EEPROM.write(i,password[pAddr]);
    pAddr++;
  }
  
  EEPROM.commit();
}

