/*
 * Cr. Chatpeth Kenanan
 * Nexpie Giant team
 * ch.ee.psu@outlook.com
 */

#include "NX2003.h"

NX2003BTN btn1;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println("Hello");
  btn1.init();
}

void loop() {
  Serial.println("No matter how the button pressed in a delay, we still know!");
  // Serial.println(btn1.read());
  if(btn1.pressed())
  {
    Serial.println("Button pressed!");
  }
  delay(1000);
}
