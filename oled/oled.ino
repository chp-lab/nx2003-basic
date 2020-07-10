#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 32
#define SDA 4
#define SCK 22
int count = 100;

#define OLED_RESET -1
// Set screen width and screen height of OLED, and Communicate chanel by using &Wire
Adafruit_SSD1306 OLED(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup(){
    Serial.begin(115200);
    // Set SDA pin = 19, and SCL/SCK pin = 22 (or any gpio on wemos lolin32)`
    // Wire.begin(SDA,SCL/SCK); <---- how to use function
    Wire.begin(SDA, SCK);
    OLED.begin(SSD1306_SWITCHCAPVCC, 0x3C);
    OLED.clearDisplay();
    OLED.setTextColor(WHITE);
    OLED.setCursor(0, 0);
    OLED.setTextSize(2);
    OLED.println("Test");
    OLED.display();
}

void loop(){
  OLED.clearDisplay();
  OLED.setCursor(0, 0);
  if(count == 0){
    OLED.println("Time out");
  }else if(count < 0){
    count = 60;
    delay(2000);
    return;
  }else{
    OLED.println(String(count));
  }
  OLED.display();
  Serial.println(count);
  delay(1000);
  count = count - 1;
}
