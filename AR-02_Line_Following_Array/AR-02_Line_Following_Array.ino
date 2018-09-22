int serialData0, serialData1, serialData2, sens;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}
void Print(int sens1, int sens2, int sens3){
  sens = (sens1 + sens2 + sens3) / 3;
  Serial.println(sens);
}
void loop() {
  // put your main code here, to run repeatedly:
 serialData0 = analogRead(A0);
 //delay(10);
 serialData1 = analogRead(A1);
 //delay(10);
 serialData2 = analogRead(A2);
 Print(serialData0, serialData1, serialData2);
 delay(10);
}
