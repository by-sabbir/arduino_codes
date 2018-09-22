#include <SoftwareSerial.h>;

SoftwareSerial bluetooth(0, 1); // RX, TX
char;
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
//    if (BluetoothData == '0')
//    {
//      digitalWrite(12, LOW);
//      Serial.print("LED Off");
//    }
//
//    if (BluetoothData == '1')
//    {
//      digitalWrite(12, HIGH);
//      Serial.print("LED On");
//    }
  }
  delay(100);
}
