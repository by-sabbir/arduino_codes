#include "Keyboard.h"

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
  while (digitalRead(2) == HIGH) {
    // new document:
    Keyboard.press(ctrlKey);
    Keyboard.press(altKey);
    Keyboard.press('t');
    delay(100);
    Keyboard.print('figlet Agrohii');
    //delay(10);
    //keyboard.press('19');
    //delay(10);
    //keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(500);
  }
  // wait for new window to open:
  delay(500);
}
