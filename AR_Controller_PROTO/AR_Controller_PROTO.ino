#include <SoftwareSerial.h>;

SoftwareSerial bluetooth(0, 1); // RX, TX
String BluetoothData;

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
    
    if (BluetoothData == "TO")
    {
      digitalWrite(5,HIGH);
      Serial.println(BluetoothData);
      delay(10);

    }

    if (BluetoothData == "TF")
    {
      digitalWrite(5,LOW);
      Serial.println(BluetoothData);
      delay(10);
    }
    delay(10);
  }
}
