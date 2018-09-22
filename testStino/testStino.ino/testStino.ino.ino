int val;
void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(constrain(map(analogRead(0),0,1023,0,255), 0, 255));
  delay(50);
}
