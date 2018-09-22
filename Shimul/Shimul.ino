int cds, mappedCds;
void setup() {
  pinMode(7, OUTPUT);
}

void loop() {
  cds = analogRead(0);
  mappedCds = map(cds, 0, 1023, 0, 100);
  delay(2000);
  if (mappedCds <= 40){
    digitalWrite(7, HIGH);
  }
  else  digitalWrite(7, LOW);
}
