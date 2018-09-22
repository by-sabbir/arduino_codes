           /*  Project Smart Light
     By- Team "Agrohi"
     Coded by- Sabbir Ahmed
*/

//Defining RELAY PINs
#define r1 2
#define r2 3
#define r3 4
#define r4 5
#define r5 6
#define r6 7

//Defining PIR PINs
#define p1 8
#define p2 9
#define p3 10
#define p4 11
#define p5 12
#define p6 13

int pirState1 = LOW, pirState2 = LOW, pirState3 = LOW, pirState4 = LOW, pirState5 = LOW, pirState6 = LOW; // we start, assuming no motion detected
int pir1 = 0, pir2 = 0, pir3 = 0, pir4 = 0, pir5 = 0, pir6 = 0; // variable for reading the pin status
//pir calibration
int cal, watch, ledOnStat;
// variable for sensing light
//int cdsValue, mappedCds;

void setup() {
  pinMode(r1, OUTPUT); // declare RELAY as output
  pinMode(p1, INPUT); // declare sensor as input
  pinMode(r2, OUTPUT); // declare RELAY as output
  pinMode(p2, INPUT); // declare sensor as input
  pinMode(r3, OUTPUT); // declare RELAY as output
  pinMode(p3, INPUT); // declare sensor as input
  pinMode(r4, OUTPUT); // declare RELAY as output
  pinMode(p4, INPUT); // declare sensor as input
  pinMode(r5, OUTPUT); // declare RELAY as output
  pinMode(p5, INPUT); // declare sensor as input
  pinMode(r6, OUTPUT); // declare RELAY as output
  pinMode(p6, INPUT); // declare sensor as input

  //switching off relays
  digitalWrite(r1, HIGH);
  digitalWrite(r2, HIGH);
  digitalWrite(r3, HIGH);
  digitalWrite(r4, HIGH);
  digitalWrite(r5, HIGH);
  digitalWrite(r6, HIGH);

  //Serial Printing & Calculation
  Serial.begin(9600);
  delay(1000);
  Serial.println();
  Serial.println();
  Serial.println("----- A Product of \"Agrohi\"-----");
  Serial.println();
  Serial.println("Calibrating Sensors Please Wait...");
  for (cal = 0; cal <= 29; cal++) {
    delay(500);
    Serial.print("-");
    delay(500);
    Serial.print("-");
  }
  Serial.println();
  Serial.println("Done!");
}

void loop() {
  //Device One
  pir1 = digitalRead(p1); // read input pirue
  if (pir1 == HIGH) { // check if the input is HIGH
    if (pirState1 == LOW) {
      // we have just turned on
      digitalWrite(r1, LOW); // turn RELAY ON
      Serial.println("Device One On - Motion detected!");
      //delay(20000);
      // We only want to print on the output change, not state
      pirState1 = HIGH;
    }
  } else {

    if (pirState1 == HIGH) {
      // we have just turned of
      digitalWrite(r1, HIGH); // turn RRLAY OFF
      Serial.println("Motion ended! - Device One");
      // We only want to print on the output change, not state
      pirState1 = LOW;
    }
  }

  //Device Two
  pir2 = digitalRead(p2); // read input pirue
  if (pir2 == HIGH) { // check if the input is HIGH
    if (pirState2 == LOW) {
      // we have just turned on
      digitalWrite(r2, LOW); // turn RELAY ON
      Serial.println("Device Two On - Motion detected!");
      //delay(20000);
      // We only want to print on the output change, not state
      pirState2 = HIGH;
    }
  } else {

    if (pirState2 == HIGH) {
      // we have just turned of
      digitalWrite(r2, HIGH); // turn RRLAY OFF
      Serial.println("Motion ended! - Device Two");
      // We only want to print on the output change, not state
      pirState2 = LOW;
    }
  }

  //Device Three
  pir3 = digitalRead(p3); // read input pirue
  if (pir3 == HIGH) { // check if the input is HIGH
    if (pirState3 == LOW) {
      // we have just turned on
      digitalWrite(r3, LOW); // turn RELAY ON
      Serial.println("Device Three On - Motion detected!");
      //delay(20000);
      // We only want to print on the output change, not state
      pirState3 = HIGH;
    }
  } else {

    if (pirState3 == HIGH) {
      // we have just turned of
      digitalWrite(r3, HIGH); // turn RRLAY OFF
      Serial.println("Motion ended! - Device Three");
      // We only want to print on the output change, not state
      pirState3 = LOW;
    }
  }

  //Device Four
  pir4 = digitalRead(p4); // read input pirue
  if (pir4 == HIGH) { // check if the input is HIGH
    if (pirState4 == LOW) {
      // we have just turned on
      digitalWrite(r4, LOW); // turn RELAY ON
      Serial.println("Device Four On - Motion detected!");
      //delay(20000);
      // We only want to print on the output change, not state
      pirState4 = HIGH;
    }
  } else {

    if (pirState4 == HIGH) {
      // we have just turned ofd
      digitalWrite(r4, HIGH); // turn RRLAY OFF
      Serial.println("Motion ended! - Device Four");
      // We only want to print on the output change, not state
      pirState4 = LOW;
    }
  }

  //Device Five
  pir5 = digitalRead(p5); // read input pirue
  if (pir5 == HIGH) { // check if the input is HIGH
    if (pirState5 == LOW) {
      // we have just turned on
      digitalWrite(r5, LOW); // turn RELAY ON
      Serial.println("Device Five On - Motion detected!");
      //delay(300000);
      // We only want to print on the output change, not state
      pirState5 = HIGH;
    }
  } else {

    if (pirState5 == HIGH) {
      // we have just turned of
      digitalWrite(r5, HIGH); // turn RRLAY OFF
      Serial.println("Motion ended!- Device Five");
      // We only want to print on the output change, not state
      pirState5 = LOW;
    }
  }

  //Device Six
  pir6 = digitalRead(p6); // read input pirue
  if (pir6 == HIGH) { // check if the input is HIGH
    if (pirState6 == LOW) {
      // we have just turned on
      digitalWrite(r6, LOW); // turn RELAY ON
      Serial.println("Device Six On - Motion detected!");
      //delay(20000);
      // We only want to print on the output change, not state
      pirState6 = HIGH;
    }
  } else {

    if (pirState6 == HIGH) {
      // we have just turned of
      digitalWrite(r6, HIGH); // turn RRLAY OFF
      Serial.println("Motion ended!- Device Six");
      // We only want to print on the output change, not state
      pirState6 = LOW;
    }
  }
}
