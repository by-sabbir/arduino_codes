/*  8-Channel Relay Test
      By- Sabbir Ahmed
          Team Agrohi.
*/

int i;

void setup() {
  for (i = 2; i <= 9; i++) {
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
  Serial.begin(9600);
  Serial.println("-----A product of \"Team Agrohi\"");
  Serial.println();
}

void loop() {
  for (i = 2; i <= 9; i++) {
    digitalWrite(i, LOW);
    Serial.print("RELAY NO: ");
    Serial.println(i - 1);
    delay(1000);
    digitalWrite(i, HIGH);
    Serial.print("RELAY OFF: ");
    Serial.println(i - 1);
    delay(1000);
  }
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  digitalWrite(6, LOW);
  digitalWrite(7, LOW);
  digitalWrite(8, LOW);
  digitalWrite(9, LOW);
  Serial.print("-----ALL RELAY NO-----");
  delay(3000);
}
