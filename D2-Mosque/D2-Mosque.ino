/*
 * D-2 Mosque- Automation
 * By- Agrohii
 */

int inputPin1 = 13;
int inputPin2 = 11;
int pirState1 = LOW, pirState2 = LOW;
int val1 = 0, val2 = 0;
int r1 = 9, r2 = 10; 
void setup() {
  pinMode(inputPin1, INPUT);
  pinMode(inputPin2, INPUT);
  pinMode(r1, OUTPUT);
  pinMode(r2, OUTPUT);
  Serial.begin(9600);
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);

  Serial.println("Calibrating pls wait...");
  delay(30*1000);
  
  digitalWrite(r1, LOW);
  digitalWrite(r2, LOW);
  Serial.println("Done!");
}
 
void loop(){
  val1 = digitalRead(inputPin1);
  val2 = digitalRead(inputPin2);
  if (val1 == HIGH || val2 == HIGH) {
    
    if (pirState1 == LOW) {
      digitalWrite(r1, HIGH);
      Serial.println("Motion detected!");
      pirState1 = HIGH;
    }
    if (pirState2 == LOW) {
      digitalWrite(r2, HIGH);
      Serial.println("Motion detected!");
      pirState2 = HIGH;
    }
  } else {
    digitalWrite(r1, LOW);
    digitalWrite(r2, LOW);
    if (pirState1 == HIGH){
      digitalWrite(r1, LOW);
      Serial.println("Motion ended!");
      pirState1 = LOW;
    }
    if (pirState2 == HIGH){
      digitalWrite(r2, LOW);
      Serial.println("Motion ended!");
      pirState2 = LOW;
    }
  }
/*
  //second sensor

  val2 = digitalRead(inputPin2);
  if (val2 == HIGH) {
    digitalWrite(r2, HIGH);
    if (pirState2 == LOW) {
      Serial.println("Motion detected!");
      pirState2 = HIGH;
    }
  } else {
    digitalWrite(r2, LOW);
    if (pirState2 == HIGH){
      Serial.println("Motion ended!");
      pirState2 = LOW;
    }
  } */
}
