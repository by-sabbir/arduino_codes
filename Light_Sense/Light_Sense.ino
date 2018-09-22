int cdsValue, mappedCds;


void senseDarkness() {
  cdsValue = analogRead(0);
  mappedCds = map(cdsValue, 0, 1023, 0, 100);
  Serial.println(mappedCds);
  delay(1000);
  if(mappedCds <= 15){
    deviceState();
  }
}
