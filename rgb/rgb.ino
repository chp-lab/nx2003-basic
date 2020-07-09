#define R_LED 21
#define G_LED 19
#define B_LED 18
#define INTERVAL 500

int count = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(R_LED, OUTPUT);
  pinMode(G_LED, OUTPUT);
  pinMode(B_LED, OUTPUT);
  Serial.begin(115200);
  randomSeed(analogRead(A0));
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("#Success=");
  Serial.println(count);
  count ++;
  int r = ranNum();
  int g = ranNum();
  int b = ranNum();
  rgb(r, g, b);
  delay(INTERVAL);
}

int ranNum()
{
  return random(0, 2);
}
void rgb(int r, int g, int b)
{
  digitalWrite(R_LED, r);
  digitalWrite(G_LED, g);
  digitalWrite(B_LED, b);
}
