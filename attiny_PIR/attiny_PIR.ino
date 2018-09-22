#define ledPin 0
#define inputPin 1

int pirState = LOW; // we start, assuming no motion detected
int pirVal = 0; // variable for reading the pin status

void setup() {
  pinMode(ledPin, OUTPUT); // declare LED as output
  pinMode(inputPin, INPUT); // declare sensor as input
  delay(30000);
}

void loop() {
  pirVal = digitalRead(inputPin); // read input pirValue
  if (pirVal == HIGH) { // check if the input is HIGH
    digitalWrite(ledPin, HIGH); // turn LED ON
    if (pirState == LOW) {
      pirState = HIGH;
    }
  } else {
    digitalWrite(ledPin, LOW); // turn LED OFF
    if (pirState == HIGH) {
      pirState = LOW;
    }
  }
}
