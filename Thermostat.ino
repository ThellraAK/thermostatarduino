void therminit(){
  pinMode(2, OUTPUT); // Relay connected here
  pinMode(LED_BUILTIN, OUTPUT); // just to have a red light when it happens on the board
  onat = millis(); // need somewhere to start at
  offat = millis(); //same
  highsetpoint = 74; //turn off heat when we reach this one
  lowsetpoint = 61; //turn off heat if we drop below this
  heateron = false; //initially have heat off
  callforheat =false; //initially have heat off
}

void thermloop(){
    //alltheheat(float high, float low, float current
  calltheheat(highsetpoint, lowsetpoint, Long_myBMP_TEMP.getAverage());
  thermostat();
  turnonheat(callforheat);
}

void thermostat(){
  unsigned long nowT = millis();
  if (heateron == false && callforheat == true )  {
    unsigned long offdur = nowT - offat;
    if (offdur >= mindur ){
      heateron = true;
      onat = millis();
    }
  }
  if (heateron == true && callforheat == false) {
    unsigned long ondur = nowT - onat;
    if (ondur >= mindur ) {
      heateron = false;
      offat = millis();
    }
  }
    
  }
  
void calltheheat(float high, float low, float current) {

  if (current <= low) {
    callforheat = true ;
  }

  if (current >= high ) {
    callforheat = false;
  }
  turnonheat(callforheat);
}

void turnonheat(bool heatcalledfor){
  if (heatcalledfor == true){
    digitalWrite(2, HIGH);
    digitalWrite(LED_BUILTIN, HIGH); 
  }
  if (heatcalledfor == false) {
    digitalWrite(2, LOW);
    digitalWrite(LED_BUILTIN, LOW); 
  }
}
