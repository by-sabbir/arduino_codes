#include <Keypad.h>
const byte numRows = 4;
const byte numCols = 4;
char keymap[numRows][numCols] =
{
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
byte rowPins[numRows] = {9, 8, 7, 6};
byte colPins[numCols] = {5, 4, 3, 2};
Keypad myKeypad = Keypad(makeKeymap(keymap), rowPins, colPins,
                         numRows, numCols);
void setup()
{
  pinMode(10, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  char keypressed = myKeypad.getKey();
  if (keypressed != NO_KEY)
  {
    Serial.print(keypressed);
    if (keypressed == '2') {
      digitalWrite(10, HIGH);
      Serial.println("10 HIGH");
    }
    if (keypressed == '0') {
      digitalWrite(10, LOW);
      Serial.println("10 LOW");
    }
  }
}
