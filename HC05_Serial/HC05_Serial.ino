#include <SoftwareSerial.h>

SoftwareSerial bluetooth(0, 1); // RX, TX
char BluetoothData, i;
void setup()
{
  for( i = 2; i <= 9; i++){
    pinMode(i, OUTPUT);
    digitalWrite(i, HIGH);
  }
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop()
{
  while (bluetooth.available()){
    BluetoothData = bluetooth.read();
    Serial.println(BluetoothData);
  }
}
