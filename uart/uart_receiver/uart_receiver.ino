#define R_LED 21
#define G_LED 19
#define B_LED 18

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(R_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);
  pinMode(B_LED, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  char key = '0';
  while(Serial.available())
  {
    key = Serial.read();
    Serial.print(key);
    if(key == 'R')
    {
      rgb(LOW, HIGH, HIGH);
    }
    else if(key == 'G')
    {
      rgb(HIGH, LOW, HIGH);
    }
    else if(key == 'B')
    {
      rgb(HIGH, HIGH, LOW);
    }
    else if(key == 'F')
    {
      rgb(HIGH, HIGH, HIGH);
    }
    else if(key == 'N')
    {
      rgb(LOW, LOW, LOW);
    }
  }
  Serial.println(".");
  delay(1000);
}

void rgb(int r, int g, int b)
{
  digitalWrite(R_LED, r);
  digitalWrite(G_LED, g);
  digitalWrite(B_LED, b);
}
