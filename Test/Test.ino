char btData;
void setup() {
  Serial.begin(9600);
  Serial1.begin(9600);
}

void loop() {
  if (Serial.available()) {
    btData = Serial.read();
    Serial.println(btData);
    
  }
  if (Serial1.available()) {
    btData = Serial1.read();
    Serial1.println(btData);
  }
}
