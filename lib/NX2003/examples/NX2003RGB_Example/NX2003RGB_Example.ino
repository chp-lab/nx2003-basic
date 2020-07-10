#include "NX2003.h"
#define delay_time 1500
NX2003RGB RGB; // create NX2003RGB object

void setup() {
  Serial.begin(115200);
  RGB.begin(); // using RGB

	// Uncomment statment below, if RGB led is not common cathode
  // RGB.setCommonCathode(false);
}

void loop() {
  RGB.red();  // set RGB LED to red
  delay(delay_time);
  
  RGB.green(); // set RGB LED to green
  delay(delay_time);
  
  RGB.blue(); // set RGB LED to blue
  delay(delay_time);
  
  RGB.yellow(); // set RGB LED to yellow 
  delay(delay_time);
  
  RGB.pink(); // set RGB LED to pink
  delay(delay_time);
  
  RGB.orange(); // set RGB LED to orange
  delay(delay_time);
  
  RGB.lightblue(); // set RGB LED to lightblue
  delay(delay_time);
  
  RGB.lightgreen(); // set RGB LED to lightgreen
  delay(delay_time);

  RGB.white(); // set RGB LED to white
  delay(delay_time);
  
  RGB.off(); // set RGB LED to turn off
  delay(delay_time);
}