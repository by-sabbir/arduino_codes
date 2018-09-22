#define face 7
#define eye 8
char data;
void setup() {
  pinMode(face, OUTPUT);
  pinMode(eye, OUTPUT);                                                                                                                                                                                                                                                                                                                                                                                                                                                                         
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    data = Serial.read();
    if (data == 'e') digitalWrite(eye, HIGH);
    if (data == 'f') digitalWrite(face, HIGH);
  }
  delay(90);
  digitalWrite(face, LOW);
  digitalWrite(eye, LOW);
}
