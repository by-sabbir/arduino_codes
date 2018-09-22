
/* PIR sensor tester*/

int relayPin = 7; // choose the pin for the Device
int inputPin = 2; // choose the input pin (for PIR sensor)
int pirState = LOW; // we start, assuming no motion detected
int pirVal = 0; // variable for reading the pin status
//pir calibration
int cal, watch, ledOnStat;

// variable for sensing light
int cdsValue, mappedCds;

void setup() {
  pinMode(relayPin, OUTPUT); // declare RELAY as output
  pinMode(inputPin, INPUT); // declare sensor as input

  Serial.begin(9600);
  delay(1000);
  Serial.println();
  Serial.println();
  Serial.println("********Programmed By- Sabbir Ahmed");
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
  watch = millis()/1000;
  if(Serial.read() == 't'){
    Serial.print("Total Working time: ");
    Serial.print(watch);
    Serial.println(" Seconds");
    
  }
  
  cdsValue = analogRead(0);
  mappedCds = map(cdsValue, 0, 1023, 0, 100);
  //Serial.println(mappedCds);
  if (mappedCds > 15) {
    delay(1000);
    digitalWrite(relayPin, LOW); // turn LED OFF
    Serial.println("--------------Device Deactivated (Enough Light)--------------");
  }
  else if (mappedCds <= 30) {
    
    //Serial.println("--------------Device Active--------------");
    pirVal = digitalRead(inputPin); // read input pirValue
    if (pirVal == HIGH) { // check if the input is HIGH
      if (pirState == LOW) {
        // we have just turned on
        digitalWrite(relayPin, HIGH); // turn RELAY ON
        Serial.println("Motion detected!");
        delay(300000);
        // We only want to print on the output change, not state
        pirState = HIGH;
      }
    } else {
      
      if (pirState == HIGH) {
        // we have just turned of
        digitalWrite(relayPin, LOW); // turn RRLAY OFF
        Serial.println("Motion ended!");
        // We only want to print on the output change, not state
        pirState = LOW;
      }
    }
  }
}


