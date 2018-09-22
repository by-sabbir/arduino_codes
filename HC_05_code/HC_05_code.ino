#include <SoftwareSerial.h>
//
SoftwareSerial bluetooth(0, 1);
int BluetoothData;
void setup()
{
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop()
{
  while (bluetooth.available())
  {
    BluetoothData = bluetooth.read();
    Serial.println(BluetoothData);
  }
}
