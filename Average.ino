void avg_clean(){
   mySI_TEMP.clear();
  mySI_HUM.clear();
  myBMP_PRES.clear();
  myBMP_TEMP.clear();
  Long_mySI_TEMP.clear();
  Long_mySI_HUM.clear();
  Long_myBMP_PRES.clear();
  Long_myBMP_TEMP.clear();
}

void avg_sensors(float cur_bmp_temp, float cur_bmp_pres, float cur_si_hum, float cur_si_temp ){
  
 mySI_TEMP.addValue(cur_si_temp);
 mySI_HUM.addValue(cur_si_hum);
 myBMP_PRES.addValue(cur_bmp_pres);
 myBMP_TEMP.addValue(cur_bmp_temp);
 if (samples % sizeofaverage == 0){
  Long_avg_sensors(myBMP_TEMP.getAverage(), myBMP_PRES.getAverage(), mySI_HUM.getAverage(), mySI_TEMP.getAverage());
  Long_print_avg();


 }
 
 
 samples++;
 
 
}

void Long_avg_sensors(float avg_bmp_temp, float avg_bmp_pres, float avg_si_hum, float avg_si_temp ){
  
 Long_mySI_TEMP.addValue(avg_si_temp);
 Long_mySI_HUM.addValue(avg_si_hum);
 Long_myBMP_PRES.addValue(avg_bmp_pres);
 Long_myBMP_TEMP.addValue(avg_bmp_temp);
 Longsamples++;
 
}
