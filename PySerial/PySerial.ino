int a;
void setup() {
  pinMode(13, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  a = Serial.read();
  if (a == 'a'){
    digitalWrite(13, HIGH);
  }
  else if (a == 'b'){
    digitalWrite(13, LOW);
  }
}
