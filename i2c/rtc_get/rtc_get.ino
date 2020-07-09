#include <Wire.h>
#include "DS3231.h"


#define SDA 4
#define SCL 22

RTClib RTC;

void setup() {
  /**
  * เริ่มการสื่อสารกับ Serial monitor
   */
      Serial.begin(115200);

  /**
  * เริ่มการสื่อสารแบบ I2C
   */
      Wire.begin(SDA, SCL);
}

void loop () {
    /**
     * หน่วงเวลาดึงทุกๆ 1 วินาที
     */
        delay(1000);

    /**
     * ดึงเวลาจากโมดูล RTC ด้วยคำสั่ง RTC.now() เก็บไว้ใน object ชือว่า now 
     * ซึ่งสามารถเรียกดึง วันเดือนปีชั่วโมงนาทีวินาที ได้ผ่านฟังก์ชันตัวอย่างด้านล่าง
     */
        DateTime now = RTC.now();
        
        Serial.print(now.year(), DEC);
        Serial.print('/');
        Serial.print(now.month(), DEC);
        Serial.print('/');
        Serial.print(now.day(), DEC);
        Serial.print(' ');
        Serial.print(now.hour(), DEC);
        Serial.print(':');
        Serial.print(now.minute(), DEC);
        Serial.print(':');
        Serial.print(now.second(), DEC);
        Serial.println();
}
