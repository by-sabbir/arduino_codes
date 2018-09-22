/* ------Smart Light Project
         Dr. Wazed Building
         Ground Floor
         Programmed by- Agrohi
         Proud Team Member of ***AGROHI**
*/
int i;
//Front Gate
int r1 = 9; // Relay Switch Front Gate
int p1 = 11; // PIR sensor Front Gate

//Stare Ground Floor
int r2 = 10; // Relay Switch Front Gate
int p2 = 12; // PIR sensor Front Gate
int p3 = 13;
//variables Gate
int pirState = LOW;
int pirVal = 0;
// variables Stare
int pirState1 = LOW;
int pirVal1 = 0;

int pirState2 = LOW;
int pirVal2 = 0;

void setup() {
  pinMode(r1, OUTPUT);
  pinMode(p1, INPUT);
  pinMode(r2, OUTPUT);
  pinMode(p2, INPUT);
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  Serial.begin(9600);
  delay(5);
  Serial.println("            Programmed By- Sabbir Ahmed");
  Serial.println();
  Serial.println("Calibrating Sensors Please Wait...");
  for (i = 1; i < 30 ; i++) {
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

  //First Sensor
  pirVal = digitalRead(p1); // read input pirValue
  if (pirVal == HIGH) { // check if the input is HIGH
    if (pirState == LOW) {
      // we have just turned on
      digitalWrite(r1, HIGH); // turn RELAY ON
      Serial.println("Motion detected!- On Device 1");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {

    if (pirState == HIGH) {
      // we have just turned of
      digitalWrite(r1, LOW); // turn RRLAY OFF
      Serial.println("Motion ended!- On Device 1");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }


  //Second Sensor

  pirVal1 = digitalRead(p2); // read input pirValue
  if (pirVal1 == HIGH) { // check if the input is HIGH
    if (pirState1 == LOW) {
      // we have just turned on
      digitalWrite(r2, HIGH); // turn RELAY ON
      Serial.println("Motion detected!-On Device 2a");
      // We only want to print on the output change, not state
      pirState1 = HIGH;
    }
  } else {

    if (pirState1 == HIGH) {
      // we have just turned of
      digitalWrite(r2, LOW); // turn RRLAY OFF
      Serial.println("Motion ended!-On Device 2a");
      // We only want to print on the output change, not state
      pirState1 = LOW;
    }
  }

  //Third Sensor

  if (digitalRead(p2) == LOW) {
    pirVal2 = digitalRead(p3); // read input pirValue
    if (pirVal2 == HIGH) { // check if the input is HIGH
      if (pirState2 == LOW) {
        // we have just turned on
        digitalWrite(r2, HIGH); // turn RELAY ON
        Serial.println("Motion detected!-On Device 2b");
        // We only want to print on the output change, not state
        pirState2 = HIGH;
        pirVal2 = LOW;
      }
    }
  }
  if (digitalRead(p3) == LOW) {
    if (pirState2 == HIGH) {
      // we have just turned off
      digitalWrite(r2, LOW); // turn RRLAY OFF
      Serial.println("Motion ended!-On Device 2b");
      // We only want to print on the output change, not state
      pirState2 = LOW;
    }
  }
  Serial.flush();
}
