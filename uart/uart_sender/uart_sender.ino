void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

char LED[] = {'R', 'G', 'B', 'N', 'F'};

void loop() {
  // put your main code here, to run repeatedly:
  int i;
  for(i = 0; i < 5; i++)
  {
    int byteSent = Serial.write(LED[i]);
    Serial.println();
    delay(1000);  
  }
}
