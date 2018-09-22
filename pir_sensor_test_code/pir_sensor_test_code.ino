/* PIR sensor tester
   copyright - playground.arduino.cc/
   Modded By- Sabbir Ahmed
   Mail: sabbir.eee.hstu@gmail.com
   Date: 21/08/2015
*/

int relayPin = 9; // choose the pin for the LED
int inputPin = 11; // choose the input pin (for PIR sensor)
int pirState = LOW; // we start, assuming no motion detected
int pirVal = 0; // variable for reading the pin status
int t1, t2, t, T,i;
void setup() {
  pinMode(relayPin, OUTPUT); // declare LED as output
  pinMode(inputPin, INPUT); // declare sensor as input
  Serial.begin(9600);
  digitalWrite(relayPin, HIGH);
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
}

void loop() {
  pirVal = digitalRead(inputPin); // read input pirValue
  if (pirVal == HIGH) { // check if the input is HIGH
    digitalWrite(relayPin, HIGH); // turn LED ON
    if (pirState == LOW) {
      // we have just turned on
      t1 = millis() / 1000;
      Serial.write('a');
      Serial.println("Motion detected!");
      Serial.print("Time: ");
      Serial.println(t1);
      pirState = HIGH;
    }
  } else {
    digitalWrite(relayPin, LOW); // turn LED OFF
    if (pirState == HIGH) {
      // we have just turned of
      t2 = millis() / 1000;
      Serial.println("Motion ended!");
      t = t2 - t1;
      Serial.print("End Time: ");
      Serial.println(t);
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
  Serial.flush();
}
