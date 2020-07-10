#include "NX2003.h"

/* 
	Create object NX2003I2C. 
	This object is set default I2C pin, SDA = 4(GPIO4), SCL = 22(GPIO22) 
*/
NX2003I2C i2cOnBoard; 

/* 
	Create object with specific SDA and SCL pin
	First argument is SDA pin, and seccond is SCL pin
*/
// NX2003I2C i2cOnBoard(0,22);

void setup() {
  Serial.begin(115200);
  // Start using NX2003I2C
  i2cOnBoard.begin();
}

void loop() {
  
  // Scan I2C devices that connected I2C pin
  int nDevice = i2cOnBoard.scanI2CDevice();
  Serial.print("Number of I2C connected : ");
  Serial.println(nDevice);

  // Show I2C devices address
  Serial.println("----- List I2C Devices Address -----");
  if (nDevice == 0){
    Serial.println("No I2C device is connected");
  } else {
    for(byte address = 1; address < 127; address++){
      if(i2cOnBoard.hasDeviceAddress(address)){
        Serial.print("- Address 0x");
        if (address < 16) {
          Serial.print("0");
        }
        Serial.println(address, HEX);
      }
    }
  }
  delay(1000);
}
