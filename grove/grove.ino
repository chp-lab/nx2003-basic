#define GROVE1_SIG 33
#define GROVE1_NC 32
#define ADC_STEP 4095
#define MAX_VOLTAGE 3.3

const int grove_sig = GROVE1_SIG;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(grove_sig, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int adc_value = analogRead(GROVE1_SIG);
  float volt = MAX_VOLTAGE*adc_value/ADC_STEP;
  Serial.println("adc_value=" + String(adc_value));
  Serial.println("voltage=" + String(volt) + " V");
  delay(1000);
}
