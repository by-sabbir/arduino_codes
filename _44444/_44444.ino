/*    -----------HSTU AUTOMATION
      -----------Dr Wazed Building
      -----------1st Floor FrontLeft
      -----------By Team **Agrohii*
      ----------------Programmed By- Sabbir Ahmed
*/
int i;
/*
        Sensor Stare Case
*/
//Entry
int p1 = 2;
//Exit
int p2 = 3;
/*
        Sensor Corridor
*/
//Entry
int p3 = 4;
//Exit
int p4 = 5;

int pirState1 = LOW, pirState2 = LOW, pirState3 = LOW, pirState4 = LOW;
int pirVal1 = 0, pirVal2 = 0, pirVal3 = 0, pirVal4 = 0;

//Entry Exit Switching
int r1 = 8;
int r2 = 9;

void setup() {
  for (i = 2; i <= 7; i++) {
    pinMode(i, INPUT);
  }
  pinMode (r1, OUTPUT);
  pinMode(r2, OUTPUT);
  delay(5);
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  Serial.begin(9600);
  delay(5);
  Serial.println("            Programmed By- Sabbir Ahmed");
  Serial.println();
  Serial.println("Calibrating Sensors Please Wait...");
  for (i = 1; i <= 30 ; i++) {
    Serial.print(".");
    delay(500);
    Serial.print(".");
    delay(500);
  }
  Serial.println();
  Serial.println("Done!");
  Serial.println();
  digitalWrite(r1, LOW);
  digitalWrite(r2, LOW);
}


void loop() {

  /*
        Stare Case Entry And Exit
  */

  pirVal1 = digitalRead(p1);
  pirVal2 = digitalRead(p2);

  // Active State
  if (pirVal1 == HIGH || pirVal2 == HIGH) {

    digitalWrite(r1, HIGH);

    if (pirState1 == LOW || pirState2 == LOW) {
      Serial.println("          Motion detected!");
      Serial.println("___Sensor P1 And P2 Active___");
      pirState1 = HIGH;
      pirState2 = HIGH;
    }
  }

  //Deactive State
  else {

    digitalWrite(r1, LOW);

    if (pirState1 == HIGH || pirState2 == HIGH) {
      Serial.println("          Motion ended!");
      Serial.println("___Sensor P1 And P2 Deactive___");
      pirState1 = LOW;
      pirState2 = LOW;
    }
  }

  /*
        Corridor Entry And Exit
  */

  pirVal3 = digitalRead(p3);
  pirVal4 = digitalRead(p4);

  // Active State
  if (pirVal3 == HIGH || pirVal4 == HIGH) {

    digitalWrite(r2, HIGH);

    if (pirState3 == LOW || pirState4 == LOW) {
      Serial.println("          Motion detected!");
      Serial.println("___Sensor P3, P4 Active___");
      pirState3 = HIGH;
      pirState4 = HIGH;
    }
  }

  //Deactive State
  else {

    digitalWrite(r2, LOW);    

    if (pirState3 == HIGH || pirState4 == HIGH) {
      Serial.println("          Motion ended!");
      Serial.println("___Sensor P3, P4 Deactive___");
      pirState3 = LOW;
      pirState4 = LOW;
    }
  }
  Serial.flush();
}
