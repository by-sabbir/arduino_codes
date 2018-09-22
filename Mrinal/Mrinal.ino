#include <LiquidCrystal.h>

LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
int count = 0;
void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(2, 0);
  lcd.print("Object Counter");
}

void loop(){
  lcd.setCursor(6, 1);
  if (analogRead(0) < 900){
    count++;
  }
  lcd.print(count);
  delay(100);
  Serial.println(count);
}

