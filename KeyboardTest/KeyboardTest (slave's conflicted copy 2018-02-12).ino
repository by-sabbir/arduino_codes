#include "Keyboard.h"
int i;
char ctrlKey = KEY_LEFT_CTRL;
char altKey =  KEY_LEFT_ALT;

void setup() {
  // make pin 2 an input and turn on the
  // pullup resistor so it goes high unless
  // connected to ground:
  pinMode(2, INPUT_PULLUP);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  while (digitalRead(2) == LOW) {
    Keyboard.press(KEY_TAB);
    Keyboard.release();
    for(i=0; i<=6; i++){
      Keyboard.press(KEY_DOWN_ARROW);
      Keyboard.release();
    }
  }
  // wait for new window to open:
  delay(500);
}
