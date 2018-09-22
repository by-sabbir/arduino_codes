int i;
void setup() {
  for(i=2; i<=13;i++){
    pinMode(i, OUTPUT);
  }
  Serial.begin(9600);
}

// the loop function runs over and over again forever
void loop() {
  for(i=2; i<=13;i++){
    digitalWrite(i,HIGH);
    delay(150);
    Serial.println(i);
    digitalWrite(i,LOW);
    delay(150);
  }
}
