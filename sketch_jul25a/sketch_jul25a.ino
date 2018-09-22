char in;
void setup() {
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  in = Serial.read();
  if (in == 'd'){
    digitalWrite(7,HIGH);
    digitalWrite(8, LOW);
    Serial.println("Face Detected ");
    delay(50);
    digitalWrite(7, LOW);
  }
  if (in == 'c'){
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
    Serial.println("nothing");
  }
  if (in == 'n'){
    digitalWrite(7, LOW);
    digitalWrite(8, HIGH);
  }
  if (in == 'e'){
    digitalWrite(7, LOW);
    digitalWrite(8, LOW);
    digitalWrite(9, HIGH);
    Serial.println("Eye None");
  }
}
