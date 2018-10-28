float highsetpoint ;
float lowsetpoint ; 
int samplesperminute;
char daysOfTheWeek[7][12] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};

#include <Wire.h>
#include <MemoryFree.h>
#include <pgmStrToRAM.h>
#include <RunningAverage.h>
#include <Adafruit_Si7021.h>
#include <Adafruit_BMP280.h>
#include <RTClib.h>
#include "RTClib.h"
RTC_DS3231 rtc;
int oldsecond;
#include <Time.h>
#include <TimeLib.h>
#include <Wire.h> 
float setpointL = 61;
float setpointH = 70;
bool heateron ;
bool callforheat;
unsigned long onat ;
unsigned long offat ;
unsigned long mindur = 10000;
int sizeofaverage = 5;
RunningAverage mySI_TEMP(sizeofaverage);
RunningAverage mySI_HUM(sizeofaverage);
RunningAverage myBMP_PRES(sizeofaverage);
RunningAverage myBMP_TEMP(sizeofaverage);
int samples = 0;


int Long_sizeofaverage = 30;
RunningAverage Long_mySI_TEMP(Long_sizeofaverage);
RunningAverage Long_mySI_HUM(Long_sizeofaverage);
RunningAverage Long_myBMP_PRES(Long_sizeofaverage);
RunningAverage Long_myBMP_TEMP(Long_sizeofaverage);
 
int Longsamples;

int itercount = 0;
Adafruit_BMP280 bmp; //BMP280 Example

unsigned long oldmillis;
unsigned long newmillis;

void setup() {
  samplesperminute = 120;
  therminit();
  Serial.begin(115200);
 //   while (!Serial); // wait for serial  
  Wire.begin();
  long clockFrequency;
  clockFrequency = 400000 ;
  Wire.setClock(clockFrequency);
  bmp.begin();
  Wire.end();
  Wire.begin();
  Wire.setClock(clockFrequency);
  bmpsetup();

      Serial.println("Startup");
  // put your setup code here, to run once:
  avg_clean();
  oldmillis= millis();
  ssdsetup();
}

void loop() {
  newmillis = millis();
  sensorloop();

  if (itercount % 120 == 0 ) {
      heatercontrol(1, 6);

  }

 
//  if (itercount % 10 == 0 ) {
//      //print_avg();
//      ssdprint();

//  }
  ssdupdate();
  thermloop();  
  itercount +=1;
  float delayamount = 1000/ samplesperminute;
  unsigned long howlong = 50 - (millis() - newmillis);
  
  delay(2000);


}
