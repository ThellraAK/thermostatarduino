float longabshum(){
  
      return mass_concentration(Long_mySI_HUM.getAverage(), Long_mySI_TEMP.getAverage(), Long_myBMP_PRES.getAverage());
}

float longRhum() {
      return relative_humidity(mass_concentration(Long_mySI_HUM.getAverage(), Long_mySI_TEMP.getAverage(), Long_myBMP_PRES.getAverage()),
      Long_myBMP_PRES.getAverage(), Long_myBMP_TEMP.getAverage());
}


float ABSHum(float Pressure, float Humidity, float TEMPERATURE ){
  float e = 2.71828;
  float T = TEMPERATURE;
  float rh = Humidity;
  float absolutehum;
  absolutehum =  (6.112 * pow(e, ((17.67 * T)) /(T+243.5)) * rh * 18.02)    /   ((273.15+T) * 100.0 * 0.08314) ;
  
 // Psat = 6.112 x e^[(17.67 x T)/(T+243.5)]


  return absolutehum; 
  }

const float r = 8.31447215;
const float molar_mass_h2o = 18.01534;

float relative_humidity(float mass_concentration, float absolute_pressure, float TEMPERATURE) {
  // Based on the article, we have:
  // relative_humidity = partial_pressure_h2o * 100 / vapor_pressure
  // partial_pressure_h2o = volume_mixing_ratio * absolute_pressure
  // volume_mixing_ratio = mass_concentration / (air_density * molar_mass_h2o)
  // air_density = absolute_pressure * 100 / (r * (TEMPERATURE + 273.15))
  
  // By mathematical substitution and simplification, we get:
  float relative_humidity = mass_concentration * r * (TEMPERATURE + 273.15) / (vapor_pressure(TEMPERATURE) * molar_mass_h2o);
  return relative_humidity;
}

float mass_concentration(float relative_humidity, float TEMPERATURE, float absolute_pressure) {
  // Based on the article, we have:
  // mass_concentration = volume_mixing_ratio * air_density * molar_mass_h2o
  // volume_mixing_ratio = partial_pressure_h2o / absolute_pressure
  // partial_pressure_h2o = relative_humidity * vapor_pressure / 100
  // air_density = absolute_pressure * 100 / (r * (TEMPERATURE + 273.15))
  
  // By mathematical substitution and simplification, we get:
  float mass_concentration = relative_humidity * vapor_pressure(TEMPERATURE) * molar_mass_h2o / (r * (TEMPERATURE + 273.15));
  return mass_concentration;
}

float vapor_pressure(float TEMPERATURE) {
  const float a0 = 6.107799961;
  const float a1 = 4.436518521e-1;
  const float a2 = 1.428945805e-2;
  const float a3 = 2.650548471e-4;
  const float a4 = 3.031240396e-6;
  const float a5 = 2.034080948e-8;
  const float a6 = 6.136820929e-11;
  return a0 + TEMPERATURE *
    (a1 + TEMPERATURE *
     (a2 + TEMPERATURE  *
      (a3 + TEMPERATURE  *
       (a4 + TEMPERATURE  *
        (a5 + TEMPERATURE  * a6)))));
}
