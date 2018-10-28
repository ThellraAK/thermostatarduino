void bmpsetup(){
  Wire.beginTransmission(0x77);
  Wire.write(0xF4);
  Wire.write(255);
  Wire.write(0); //no downtime, no burst mode shit, no spi 4 wire
  
}
