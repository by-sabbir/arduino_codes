#include <LiquidCrystal.h>
#include "Keyboard.h"

LiquidCrystal lcd(7, 6, 5, 4, 3, 2);
int i, enter = 176, ctrl = 128, alt = 130, shift = 133, del = 212, space = 32;
int esc = 177, right = 215, left = 216, up = 218, down = 217, f4 = 197;
char BluetoothData;

void setup() {
  Serial1.begin(9600);
  delay(50);
  Serial.begin(9600);
  delay(50);
  lcd.begin(16, 2);
  lcd.print("VLC-Controller");
  lcd.setCursor(0, 2);
  lcd.print("-Agrohii Tech.");
  delay(100);
}

void loop() {
  if(Serial.available()){
    BluetoothData = Serial.read();
    if(BluetoothData == 'd'){
      volUp();
    }
    if(BluetoothData == 'u'){
      volDown();
    }
    if(BluetoothData == 'm'){
      mute();
    }
    if(BluetoothData == 'p'){
      prevPlay();
    }
    if(BluetoothData == 's'){
      pausePlay();
    }
    if(BluetoothData == 'n'){
      nextPlay();
    }
    if(BluetoothData == 'q'){
      exitPlayer();
    }
  }

  //Serial One
  if(Serial1.available()){
    BluetoothData = Serial1.read();
    if(BluetoothData == 'u'){
      volUp();
    }
    if(BluetoothData == 'd'){
      volDown();
    }
    if(BluetoothData == 'm'){
      mute();
    }
    if(BluetoothData == 'p'){
      prevPlay();
    }
    if(BluetoothData == 's'){
      pausePlay();
    }
    if(BluetoothData == 'n'){
      nextPlay();
    }
    if(BluetoothData == 'q'){
      exitPlayer();
    }
  }
}

char key(char key) {
  key = Keyboard.press(key);
  delay(10);
  return key;
}
int keyNum(int keyNum) {
  keyNum = Keyboard.press(keyNum);
  delay(10);
}
void rel() {
  Keyboard.releaseAll();
}

void volDown(){
 keyNum(ctrl);
 keyNum(up);
 rel(); 
}
void mute(){
  key('m');
  rel();
}
void volUp(){
  keyNum(ctrl);
  keyNum(down);
  rel();
}
void prevPlay(){
  key('p');
  rel();
}
void pausePlay(){
  key(space);
  rel();
}
void nextPlay(){
  key('n');
  rel();
}
void exitPlayer(){
  keyNum(ctrl);
  key('q');
  rel();
}
