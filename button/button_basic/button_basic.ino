#define DI 35
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115000);
  pinMode(DI, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int btn_state = digitalRead(DI);
  Serial.print("DI=");
  Serial.println(btn_state);
  if(btn_state == HIGH)
  {
    Serial.println("Button Pressed");
    while(digitalRead(DI) == HIGH)
    {
      // wait untils button release
    }
  }
  delay(500);
}
