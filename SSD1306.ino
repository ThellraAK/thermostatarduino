#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET 4
Adafruit_SSD1306 display(OLED_RESET);


void ssdsetup(){
    display.begin(SSD1306_SWITCHCAPVCC, 0x3C); 
    display.clearDisplay();
    display.display();
    display.setTextSize(1);
    display.setTextColor(WHITE);
    display.setCursor(0,0);
    display.println("Hello, world!");
    display.setCursor(0,8);
    display.println("Hello, world!");    
    display.display();
    oldsecond = 0;

}

void ssdupdate(){
  DateTime now = rtc.now();
  if ( now.second() != oldsecond ){
    ssdprint(); 
  }
  

}

void ssdprint(){
  //  Long_myBMP_PRES.getAverage(),  Long_mySI_HUM.getAverage(),  Long_mySI_TEMP.getAverage() Long_myBMP_TEMP.getAverage()
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0);
  display.print(Long_myBMP_TEMP.getAverage());
  display.print((char)247);display.println("F");
  display.print(Long_mySI_HUM.getAverage());
  display.println("% RH");
  display.print(Long_myBMP_PRES.getAverage());
  display.println(" hPa");
  display.print(lowsetpoint,1); display.print(": L");
  display.print(highsetpoint,1); display.println(": H");
  if (heateron == true) {
    display.println("Heater On");
  }
  if (heateron == false) {
    display.println("Heater Off");
  }
    DateTime now = rtc.now();
    display.print(now.month(), DEC);
    display.print('/');
    display.print(now.day(), DEC);
    display.print('/');

    display.print(now.year(), DEC);
    display.print(" ");
    display.print(now.hour(), DEC);
    display.print(':');
    display.print(now.minute(), DEC);
    display.print(':');
    display.print(now.second(), DEC);
  
  display.display();
}
