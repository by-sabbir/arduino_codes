#include "Keyboard.h"

char data;


void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  // put your setup code here, to run once:
  delay(3*1000);
  Serial.println("Ready.. ");
  Serial1.println("Ready.. ");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial1.available()){
    data = Serial1.read();
    Keyboard.press(data);
    delay(5);
    Keyboard.releaseAll();
    Serial.println(data);
  }
}

void writeIn(char text[]) {
  int i, len;
  len = strlen(text);
  //  Serial.println(text);
  for (i = 0; i < len; i++) {
    Serial.print(text[i]);
    delay(210);
  }
  Serial.println();
}
