#define coil1 8
#define coil2 9
#define coil13 10
#define coil14 11


void setup() {
  pinMode(coil1, INPUT);
  pinMode(coil2, INPUT);
  pinMode(coil3, INPUT);
  pinMode(coil4, INPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(coil4, HIGH);
  digitalWrite(coil2,LOW);
  delay(10);

  digitalWrite(coil3, HIGH);
  digitalWrite(coil1,LOW);
  delay(10);

  digitalWrite(coil4, HIGH);
  digitalWrite(coil2,LOW);
  delay(10);

  digitalWrite(coil1, HIGH);
  digitalWrite(coil3,LOW);
  delay(10);

}
