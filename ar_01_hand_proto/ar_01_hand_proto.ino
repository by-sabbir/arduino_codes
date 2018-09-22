#include <SoftwareSerial.h>;
#include<Servo.h>

SoftwareSerial bluetooth(0, 1); // RX, TX
int BluetoothData;
Servo ms;
short int i = 0;
void setup()
{
  ms.attach(9);
  Serial.begin(9600);
  bluetooth.begin(9600);
}

void loop()
{
  if(i>180 || i<0){
    if(i>180){
      i=180;
    }
    else{
      i=0;
    }
  }
  while (bluetooth.available())
  {
    BluetoothData = bluetooth.read();

    if (BluetoothData == '1') {
      ms.write(i);
      //delay(20);
      i++;
      Serial.println(i);
    }
    if (BluetoothData == '5') {
      ms.write(i);
      //delay(20);
      i--;
      Serial.println(i);
    }
    else {
      ms.write(i);
      Serial.println(i);
    }
  }
}
