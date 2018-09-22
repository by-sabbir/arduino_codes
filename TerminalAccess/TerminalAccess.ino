/*
 Keyboard Message test

 For the Arduino Leonardo and Micro.

 Sends a text string when a button is pressed.

 The circuit:
 * pushbutton attached from pin 4 to +5V
 * 10-kilohm resistor attached from pin 4 to ground

 created 24 Oct 2011
 modified 27 Mar 2012
 by Tom Igoe
 modified 11 Nov 2013
 by Scott Fitzgerald

 This example code is in the public domain.

 http://www.arduino.cc/en/Tutorial/KeyboardMessage
 */

#include "Keyboard.h"

char ctrlKey = KEY_LEFT_CTRL;
char altKey =  KEY_LEFT_ALT;

const int buttonPin = 4;          // input pin for pushbutton

void setup() {
  // make the pushButton pin an input:
  pinMode(buttonPin, INPUT);
  // initialize control over the keyboard:
  Keyboard.begin();
}

void loop() {
  // read the pushbutton:
  int buttonState = digitalRead(buttonPin);
  if ((buttonState == HIGH)) {
    Keyboard.press(ctrlKey);
    Keyboard.press(altKey);
    Keyboard.press('t');
    Keyboard.print("figlet HEY");
  }
}

