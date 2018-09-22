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
    
    if (BluetoothData == '1'){
      digitalWrite(2, HIGH);
    }

    if (BluetoothData == 'a'){
      digitalWrite(2, LOW);
    }

    if (BluetoothData == '2'){
      digitalWrite(3, HIGH);
    }

    if (BluetoothData == 'b'){
      digitalWrite(3, LOW);
    }
    if (BluetoothData == '3'){
      digitalWrite(4, HIGH);
    }

    if (BluetoothData == 'c'){
      digitalWrite(4, LOW);
    }
    if (BluetoothData == '4'){
      digitalWrite(5, HIGH);
    }

    if (BluetoothData == 'd'){
      digitalWrite(5, LOW);
    }
    if (BluetoothData == '5'){
      digitalWrite(6, HIGH);
    }

    if (BluetoothData == 'e'){
      digitalWrite(6, LOW);
    }
    if (BluetoothData == '6'){
      digitalWrite(7, HIGH);
    }

    if (BluetoothData == 'f'){
      digitalWrite(7, LOW);
    }
    if (BluetoothData == '7'){
      digitalWrite(8, HIGH);
    }

    if (BluetoothData == 'g'){
      digitalWrite(8, LOW);
    }
    if (BluetoothData == '8'){
      digitalWrite(9, HIGH);
    }

    if (BluetoothData == 'h'){
      digitalWrite(9, LOW);
    }
    if (BluetoothData == '0'){
      for (i = 2; i <= 9; i++){
        digitalWrite(i, LOW);
        delay(350);
      }
    }  
    delay(10);
  }
}
