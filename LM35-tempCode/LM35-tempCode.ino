int val;
int tempPin = 0;

void setup()
{
  Serial.begin(9600);
}
void loop()
{
  val = analogRead(tempPin);
  float mv = ( val / 1024.0) * 5000;
  int cel = mv / 10;
  int farh = (cel * 9) / 5 + 32;

  //Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.println("C");
  //Serial.println();
  //delay(1000);

  // uncomment this to get temperature in farenhite
  //Serial.print("TEMPRATURE = ");
  Serial.print(farh);
  Serial.print("FX");
  Serial.println();
  delay(1000);
}
