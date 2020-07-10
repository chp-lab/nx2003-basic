# NX2003 Library
ภายใน NX2003 Library จะประกอบด้วย 5 class ให้เรียกใช้งาน ดังนี้

- #### [NX2003I2C](#nx2003i2c-1)

- #### [NX2003SPI](#nx2003spi-1)

- #### [NX2003RGB](#nx2003rgb-1)

- #### [NX2003BTN](#nx2003btn-1)

- #### [NX2003Thermistor](#nx2003thermistor-1)

## NX2003I2C
##### ตัวอย่างการใช้งาน [สามารถดูได้ที่นี่](./examples/NX2003I2C_Example/NX2003I2C_Example.ino)
| Constructor | คำอธิบาย |
| ------| ------ |
| NX2003I2C() | สร้าง object ของ NX2003I2C class ด้วยค่า default (SDA pin = 4, SCL pin = 22)|
| NX2003I2C(int sda, int scl) | สร้าง object ของ NX2003I2C class โดยกำหนด pin ของ SDA และ SCL ด้วยตนเอง  |

| Methods | คำอธิบาย |
| ------| ------ |
| void begin() | เริ่มต้นการใช้งาน NX2003I2C |
| int scanI2CDevice() | แสดงจำนวน I2C Device ที่เชื่อมต่ออยู่ |
| bool hasDeviceAddress(int address) | ตรวจสอบว่ามี address ของ I2C Device ที่ระบุ เชื่อมต่ออยู่หรือไม่ |

## NX2003SPI
##### ตัวอย่างการใช้งาน [สามารถดูได้ที่นี่](./examples/NX2003SPI_Example/NX2003SPI_Example.ino)
| Constructor | คำอธิบาย |
| ------| ------ |
| NX2003SPI() | สร้าง object ของ NX2003SPI class ด้วยค่า default (MISO pin = 23, MOSI pin = 13, SCK pin = 14, CS pin = 27) |

| Methods | คำอธิบาย |
| ------| ------ |
|  void init() | เริ่มต้นใช้งาน NX2003SPI โดยใช้ CS pin เริ่มต้นของบอร์ด NX2003 |
| void init(byte cs_pin) | เริ่มต้นใช้งาน NX2003 โดยผู้ใช้ระบุ CS pin ที่จะใช้ |
| void mount() | ใช้สำหรับการ mount SD Card Module ที่เชื่อมต่ออยู่กับ NX2003 (กรณีที่ผู้ใช้เชื่อมต่อ SD Card Module กับ SPI port) |

## NX2003RGB
##### ตัวอย่างการใช้งาน [สามารถดูได้ที่นี่](./examples/NX2003RGB_Example/NX2003RGB_Example.ino)
| Constructor | คำอธิบาย |
| ------| ------ |
| NX2003RGB() | สร้าง object ของ NX2003RGB class โดยกำหนด pin ของ RGB led และประเภทของ RGB led ด้วยค่า default (เหมาะสำหรับใช้งาน built-in RGB led ของ NX2003 shield) |
| NX2003RGB(byte r_pin, byte g_pin, byte b_pin, bool common_cathode) | สร้าง object ของ NX2003RGB class โดยกำหนด pin ของ RGB led และประเภทของ RGB led ด้วยตนเอง  |

| Methods | คำอธิบาย |
| ------| ------ |
| void begin() | เริ่มต้นการใช้งาน NX2003RGB  |
| void setPin(byte r_pin, byte g_pin, byte b_pin) | ตั้งค่า pin ของ RGB led ( กรณีที่ผู้ใช้งานต่อ RGB led ที่ pin อื่นๆของบอร์ด NX2003) |
|void setCommonCathode(bool common_cathode)| ตั้งค่าประเภทของ RGB led ว่าเป็น common cathode หรือไม่ <br> - true : ตั้งค่า RGB led เป็น common cathode <br> - false : ตั้งค่า RGB led เป็น common anode|
| void setColor(String color) | ตั้งค่าสีให้กับ RGB led บนบอร์ด NX2003 โดยชื่อสีที่สามารถใช้ได้ มีดังนี้ <br /> red, green, blue, pink, yellow, orange, lightblue, lightgreen, white |
| void setColor(byte rgb[3]) | ตั้งค่าสีให้กับ RGB led บนบอร์ด NX2003 โดยรับค่าสีเป็น array ซึ่ง <br /> Index 0 : เป็นการกำหนดการแสดงผลของสีแดง มีค่าตั้งแต่ 0-255<br />Index 1 : เป็นการกำหนดการแสดงผลของสีเขียว มีค่าตั้งแต่ 0-255<br />Index 2 : เป็นการกำหนดการแสดงผลของสีน้ำเงิน มีค่าตั้งแต่ 0-255 |
| void setColor(byte r, byte g, byte b) | ตั้งค่าสีให้กับ RGB led บนบอร์ด NX2003 โดยจะรับ argument สำหรับการตั้งค่าสี RGB ซึ่งค่าของแต่ละ argument จะมีค่าตั้งแต่ 0-255  |
| void on() | แสดงสี RGB led ที่ถูกตั้งค่าไว้ หากไม่ได้ทำการตั้งค่าสีไว้ ถ้าเรียกใช้คำสั่งนี้ RGB led จะแสดงสีขาว |
| void on(byte r, byte g, byte b) | แสดงสี RGB led ตามที่ผู้ใช้งานกำหนดค่าผ่าน argument  ซึ่งค่าของแต่ละ argument จะมีค่าตั้งแต่ 0-255 |
| void off() | ปิดการแสดงสีของ RGB led |
| void red() | แสดงสี RGB led สีแดง|
| void green() | แสดงสี RGB led สีเขียว |
| void blue() | แสดงสี RGB led สีน้ำเงิน |
| void yellow()  | แสดงสี RGB led สีเหลือง |
| void pink() | แสดงสี RGB led สีชมพู |
| void lightblue() | แสดงสี RGB led สีน้ำเงินอ่อนอมเขียว |
| void lightgreen() | แสดงสี RGB led สีเขียวอ่อนอมฟ้า |
| void orange() | แสดงสี RGB led สีส้ม |
| void white() | แสดงสี RGB led สีขาว |
| void clear() | reset ทุกค่าสี RGB กลับเป็นค่าเริ่มต้น (ค่าเริ่มต้น คือ 255) |

## NX2003BTN
##### ตัวอย่างการใช้งาน [สามารถดูได้ที่นี่](./examples/NX2003BTN_Example/NX2003BTN_Example.ino)
| Constructor | คำอธิบาย |
| ------| ------ |
| NX2003BTN() | สร้าง object ของ NX2003BTN class โดยกำหนด pin ของปุ่มด้วยค่า default (เหมาะสำหรับใช้งาน built-in button ของ NX2003 shield) |

| Methods | คำอธิบาย |
| ------| ------ |
| void init() | เริ่มต้นการใช้งาน NX2003BTN โดยใช้ build-in button ของบอร์ด NX2003 |
| void init(int new_btn)| เริ่มต้นการใช้งาน NX2003BTN โดยผู้ใช้กำหนด pin ของ button ที่จะใช้ |
| int read() | อ่านค่าสถานะของปุ่ม (มีค่า 0 หรือ 1) |
| bool pressed() | ตรวจสอบว่ามีการกดปุ่มหรือไม่ |
| void set_di() | สร้าง listener เพื่อคอยดูสถานะของปุ่ม |
| void clear_di() | ทำเครื่องหมายว่า event ของปุ่มถูกรับรู้โดย main program แล้ว |
| void destroy_di()| ทำลาย listener ที่คอยดูสถานะของปุ่ม |

## NX2003Thermistor
##### ตัวอย่างการใช้งาน [สามารถดูได้ที่นี่](./examples/NX2003Thermistor_Example/NX2003Thermistor_Example.ino)
| Constructor | คำอธิบาย |
| ------| ------ |
| NX2003Thermistor() | สร้าง object ของ NX2003Thermistor class ด้วยค่า default (เหมาะสำหรับใช้งาน built-in thermistor ของ NX2003 shield) |
| NX2003Thermistor(<br>int pin,<br> double voltageInput,<br> double referenceResistance,<br> double nominalThermistorResistance,<br> double nominalTemperature,<br> double bValue,<br> int resolution<br>)| สร้าง object ของ NX2003Thermistor class โดยกำหนด <br>- pin ที่ thermistor เชื่อมต่ออยู่<br>- voltage input ที่ใช้งานกับ thermistor<br>- ความต้านทานที่นำมาต่อใช้งานกับ thermistor<br>- ความต้านทานของ thermistor ที่อุณหภูมิปกติ<br>- อุณหภูมิปกติของ thermistor<br>- B value ของ thermistor <br> - ADC resolution ของ analog pin <br> ด้วยตนเอง|

| Methods | คำอธิบาย |
| ------| ------ |
| void setPin (int pin) | ตั้งค่า pin ของ thermistor (กรณีที่ผู้ใช้งานต่อ thermistor ที่ pin อื่นๆของบอร์ด NX2003) |
| void setVoltageInput(double voltageInput) | กำหนดค่า VCC ที่จ่ายให้กับ thermistor |
| void setReferenceResistance(double resistance)| กำหนดค่าความต้านทานที่นำมาต่อใช้งานกับ thermistor (Resistance ภายนอกที่นำมาต่อกับ thermistor เพื่อทำ voltage divider ) |
| void setNominalThermistorResistance(double resistance)| กำหนดค่าความต้านทานของ thermistor ที่อุณหภูมิปกติ (สามารถดูได้จาก datasheet ของ thermistor) |
| void setNominalTemperature(double temperature)| กำหนดค่าอุณหภูมิปกติของ thermistor ในหน่วยองศาเซลเซียส (สามารถดูค่าอุณหภูมิปกติของ thermistor ได้จาก datasheet ของ thermistor) |
| void setBValue(double bValue)| กำหนดค่า B value (สามารถดูได้จาก datasheet ของ thermistor) |
| void setADCResolution(int adcResolution)| กำหนดค่าความละเอียดของ ADC input ที่บอร์ดสามารถอ่านได้<br /> - ESP8266 ADC resolution คือ 1023<br /> - ESP32 ADC resolution คือ 4095 |
| void setCalibrateValue(double differentTemp, bool adding)| กำหนดค่าที่จะนำมาคำนวณ เพื่อให้ thermistor อ่านอุณหภูมิได้แม่นยำขึ้น โดยส่ง argument ค่าที่ต้องการจะนำไปใช้คำนวณ และ argument สำหรับบอกว่าค่าที่นำไปคำนวณนั้น ให้นำไปลบหรือบวก (ค่าเริ่มต้น คือ การลบ) |
| double readVoltage()| อ่าน VCC จาก pin ที่ต่ออยู่กับ thermistor |
| double readThermistorResistance()| อ่านค่าความต้านของ thermistor |
| double readTemperatureCelsius()| อ่านค่าอุณหภูมิในหน่วยองศาเซลเซียส |
| double readTemperatureFarenheit() | อ่านค่าอุณหภูมิในหน่วยฟาเรนไฮต์ |
