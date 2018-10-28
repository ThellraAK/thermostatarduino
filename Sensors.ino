void sensorloop(){
  float cur_si_hum = SIreadHumidity();
  float cur_si_temp = SIreadTemperature();
  float cur_bmp_temp = bmp.readTemperature();
  float cur_bmp_pres = bmp.readPressure()/100;
  avg_sensors(cur_bmp_temp, cur_bmp_pres, cur_si_hum, cur_si_temp);
  
}




float SIreadHumidity(void) {
  Wire.beginTransmission(0x40);

  Wire.write(0xF5);
  uint8_t err = Wire.endTransmission();


  uint32_t start = millis(); // start timeout
  while(millis()-start < 500) {
    if (Wire.requestFrom(0x40, 3) == 3) {
      uint16_t hum = Wire.read() << 8 | Wire.read();
      uint8_t chxsum = Wire.read();

      float humidity = hum;
      humidity *= 125;
      humidity /= 65536;
      humidity -= 6;
 //     Wire.beginTransmission(0x40);

  //    Wire.write(0xF5);
      return humidity;
    }
    delay(1); // 1/2 typical sample processing time
  }
  return NAN; // Error timeout

}

float SIreadTemperature(void) {
  Wire.beginTransmission(0x40);
  Wire.write(0xE0);
  uint8_t err = Wire.endTransmission();


    
  uint32_t start = millis(); // start timeout
  while(millis()-start < 500) {
    if (Wire.requestFrom(0x40, 2) == 2) {
      uint16_t temp = Wire.read() << 8 | Wire.read();

      float temperature = temp;
      temperature *= 175.72;
      temperature /= 65536;
      temperature -= 46.85;
      return temperature;
    }
    delay(1); // 1/2 typical sample processing time
  }

  return NAN; // Error timeout
}

void heatercontrol(bool on, int pwrlvl){
  SI_Hset(pwrlvl);
  uint8_t Hvalue;
  uint32_t start = millis(); // start timeout
  while(millis()-start < 1000) {
    if (Wire.requestFrom(0x40, 1) == 1) {
      Hvalue = Wire.read();
    }
    delay(2);
  }
  Serial.print("Value of the heating register is: ");
  Serial.println(Hvalue);
  setHeater(on);  
}

void SI_Hset(int pwrlvl) {
      Wire.beginTransmission(0x40); //SI7021 I2C address
    Wire.write(0x51); //The Register heater is at
    Wire.write(pwrlvl); //hopefully setting it to 1
    Wire.endTransmission();

    Wire.beginTransmission(0x40);
    Wire.write((uint8_t)0x11);
    Wire.endTransmission();
}

void setHeater(bool on) {
    Wire.beginTransmission(0x40);
    Wire.write(0xE6);

    if (on) {
        Wire.write(0x3E);
        Wire.endTransmission();
    } else {
        Wire.write(0x3A);
        Wire.endTransmission();
    }

}
