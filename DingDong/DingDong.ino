// declare all pin constants
const int led = 9;
const int buzz = 6;
const int pb = 0;
int toggle = 0;
void setup() {
  //declare output pins
  pinMode (buzz, OUTPUT);
  pinMode (led, OUTPUT);
  digitalWrite (led, LOW);
}
void loop() {
  if (analogRead (pb) == 0) { // if button is pressed
    if (toggle == 0) {
      dingdong(2);
      toggle = 1; // toggle so it turns off next press
    }
  } else {
    toggle = 0;
    digitalWrite (led, LOW);
    noTone (buzz);
  }
}
void dingdong(int times) {
  int i;
  for (i = 1; i <= times; i++) {
//    delay(250);
    tone (buzz, 5000); // play a tone of a frequency of 5000Hz
    delay (50); // play for only 50 milli seconds
    noTone (buzz);  // stop the tone
    delay(50);  // stop for 50 milli seconds
    tone(buzz, 2000);   // play another tone at 2000Hz this time
    delay(50); // play for only 50 milli seconds
    noTone (buzz);  // stop the tone
    delay(500);
  }
}
