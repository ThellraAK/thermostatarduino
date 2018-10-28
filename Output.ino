//  //float abshum = ABSHum( Long_myBMP_PRES.getAverage(),  Long_mySI_HUM.getAverage(),  Long_mySI_TEMP.getAverage());
  //Serial.print("abshum output:  ");
  //  Serial.println(abshum,4);


void printtime(){
    
 

    DateTime now = rtc.now();
    Serial.print(now.year(), DEC);
    Serial.print('/');
    Serial.print(now.month(), DEC);
    Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print(" (");
    Serial.print(daysOfTheWeek[now.dayOfTheWeek()]);
    Serial.print(") ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.print(now.second(), DEC);
    Serial.println();
}

void printsensors(float cur_bmp_temp, float cur_bmp_pres, float cur_si_hum, float cur_si_temp  ){

     Serial.println("-----------");
    printtime();
    Serial.print("BMP Temp: ");
    Serial.println(cur_bmp_temp);

    Serial.print("BMP Pressure: ");
    Serial.println(cur_bmp_pres);
    Serial.print("SI Humid: ");
    Serial.println( cur_si_hum);
    Serial.print("SI TEMP: ");
    Serial.println(cur_si_temp);
}

void print_avg(){
 Serial.print("hPA Average: ");
 Serial.println(myBMP_PRES.getAverage(), 2);
 Serial.print("BMP Temp Average: ");
 Serial.println(myBMP_TEMP.getAverage(), 2);
 Serial.print("SI temp Average: ");
 Serial.println(mySI_TEMP.getAverage(), 2);
 Serial.print("SI Hum  Average: ");
 Serial.println(mySI_HUM.getAverage(), 2);

}

void Long_print_avg(){
  //Long_myBMP_TEMP.getAverage(), Long_myBMP_PRES.getAverage(), Long_mySI_HUM.getAverage(), Long_mySI_TEMP.getAverage()
  Serial.print("Long hPa Average: ");
  Serial.println(Long_myBMP_PRES.getAverage(), 2);
  Serial.print("Long BMP Temp: ");
  Serial.println(Long_myBMP_TEMP.getAverage()*1.8+32);
  float CtoF;
  CtoF = Long_myBMP_TEMP.getAverage();
  CtoF *= 1.8;
  CtoF += 32;
  Serial.print("RH%: ");
  Serial.println(longRhum());
 
  Serial.print("Long SI Temp Average: ");
  Serial.println(Long_mySI_TEMP.getAverage(), 2);
  Serial.print("Long SI Hum Average: ");
  Serial.println(Long_mySI_HUM.getAverage(), 2);
 
  if (callforheat == true){
    Serial.println("Heat Called for");
  }
  else {
    Serial.println("Heat not called for");
  }

      DateTime now = rtc.now();
    Serial.print(now.month(), DEC);
      Serial.print('/');
    Serial.print(now.day(), DEC);
    Serial.print('/');

    Serial.print(now.year(), DEC);
    Serial.print(" ");
    Serial.print(now.hour(), DEC);
    Serial.print(':');
    Serial.print(now.minute(), DEC);
    Serial.print(':');
    Serial.println(now.second(), DEC);

}
