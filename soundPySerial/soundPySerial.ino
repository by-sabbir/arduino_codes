int sens1, sens2, sens3, avg;

void setup(){
  Serial.begin(9600);
}
void loop(){
  sens1 = analogRead(0);
  delay(5);
  sens1 = map(0, 800, sens1, 0, 10);
  delay(5);
  sens2 = analogRead(1);
  delay(5);
  sens2 = map(0, 800, sens2, 0, 10);
  delay(5);
  sens3 = analogRead(2);
  delay(5);
  sens3 = map(0, 800, sens3,  0, 10);
  delay(5);
  avg = (sens1 + sens2 + sens3) / 3;
  Serial.print(sens1);  Serial.print(", ");
  Serial.print(sens2);  Serial.print(", ");
  Serial.print(sens3);  Serial.print(", ");
  Serial.print(avg);  Serial.print(", ");
  Serial.println();
  delay(100);
}

