/*
float ABSHum(float Pressure, float Humidity, float Temperature ){
  float e = 2.71828;
  float T = Temperature;
  float rh = Humidity;
  float absolutehum;
  absolutehum =  (6.112 * pow(e, ((17.67 * T)) /(T+243.5)) * rh * 18.02)    /   ((273.15+T) * 100.0 * 0.08314) ;
  
 // Psat = 6.112 x e^[(17.67 x T)/(T+243.5)]


  return absolutehum; 
  }

  */
