#include "NX2003.h"

#define THERMISTOR_PIN 39
#define VOLTAGE_INPUT 3.30
#define NOMINAL_TEMP 25
#define NOMINAL_RESISTANCE 100*1000
#define REFERENCE_RESISTANCE 100*1000 // external RESISTANCE
#define B_VALUE 3950
#define ADC_RESOLUTION 4095

/* Create thermistor object 
  @ THERMISTOR_PIN     -> NTC thermistor pin
  @ VOLTAGE_INPUT      -> voltage input to NTC thermistor
  @ REFERENCE_RESISTANCE -> resistance that using for voltage divider when connected thermistor
  @ NOMINAL_RESISTANCE   -> nominal resistance of thermistor (check thermistor datasheet)
  @ NOMINAL_TEMP       -> nominal temperature of thermistor (check thermistor datasheet)
  @ B_VALUE            -> b value of thermistor (check thermistor datasheet)
  @ ADC_RESOLUTION     -> analog input resolution of controller board
*/

NX2003Thermistor thermistor(THERMISTOR_PIN, VOLTAGE_INPUT, REFERENCE_RESISTANCE, NOMINAL_RESISTANCE, NOMINAL_TEMP, B_VALUE, ADC_RESOLUTION);

/*Create thermistor object without parameter
  Its will using following default setting
  THERMISTOR_PIN = 39
  VOLTAGE_INPUT = 3.30
  REFERENCE_RESISTANCE = 1000
  NOMINAL_RESISTANCE = 5000
  NOMINAL_TEMP = 25
  B_VALUE = 3470
  ADC_RESOLUTION = 4095
*/
// Uncomment below statement if you want to create object with default setting value
// NX2003Thermistor thermistor;

void setup() {
  Serial.begin(115200);
}

void loop() {
  float c_temp = thermistor.readTemperatureCelsius();
  float f_temp = thermistor.readTemperatureFahrenheit();
  Serial.println("Temperature celsius = " + String(c_temp));
  Serial.println("Temperature fahrenheit = " + String(f_temp));
  delay(1000);
}
