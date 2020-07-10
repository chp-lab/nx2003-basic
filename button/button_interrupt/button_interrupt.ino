#define DI 35
#define RED_LED 21

/*
 * Cr. Chatpeth Kenanan
 * Nexpie Hatyai
 * 
 * Interrupt state
 * LOW to trigger the interrupt whenever the pin is low,
 * CHANGE to trigger the interrupt whenever the pin changes value
 * RISING to trigger when the pin goes from low to high,
 * FALLING for when the pin goes from high to low.
 */
 
const byte interruptPin = DI;
const byte ledPin = RED_LED;
volatile byte state = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115000);
  pinMode(DI, INPUT);
  pinMode(RED_LED, OUTPUT);
  digitalWrite(RED_LED, !state);
  attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
}

void loop() {
  Serial.println(".");
  delay(500);
}

void blink() {
  state = !state;
  digitalWrite(ledPin, !state);
  if(state == HIGH)
  {
    Serial.println("Pressed");
  }
  else
  {
    Serial.println("Released");
  }
}
