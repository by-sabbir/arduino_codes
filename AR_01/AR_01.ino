/*
        Property of-

          Alpha Robotics (Sabbir,Easin,Kingshuk,Dipta,Polash)
          HSTU,EEE-2014.

*/



#include <SoftwareSerial.h>;
#include <Servo.h>

SoftwareSerial bluetooth(0, 1); // RX, TX
int BluetoothData;

int i = 0;
Servo ms;

void setup()
{

  Serial.begin(9600);
  bluetooth.begin(9600);
  ms.attach(9);
  ms.write(0);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
  pinMode(4, INPUT);
  pinMode(5, INPUT);
}

void loop()
{
  if (i > 180 || i < 0) {
    if (i > 180) {
      i = 180;
    }
    else {
      i = 0;
    }
  }
  while (bluetooth.available())
  {
    BluetoothData = bluetooth.read();
    //condition handMotion()
    if (BluetoothData == '1' || '5')
    {
      handMotion();
    }
    //condition forwardMoition()
    if (BluetoothData == 'u')
    {
      forwardMotion();
    }

    //condition backwardMotion()
    if (BluetoothData == 'd')
    {
      backwardMotion();
    }

    //condition leftMotion()
    if (BluetoothData == 'l')
    {
      leftMotion();
    }

    //condition rightMotion()
    if (BluetoothData == 'r')
    {
      rightMotion();
    }

    //condition flipMotion()
    if (BluetoothData == 'f')
    {
      flipMotion();
    }

    //condition flipMotion()
    if (BluetoothData == '0')
    {
      stopMotion();

    }

  }
  delay(100);
}

/*
      Motion Functions
*/

void forwardMotion() {
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  Serial.println("forward");
  Serial.println("");
}

void backwardMotion() {
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(3, LOW);
  digitalWrite(5, LOW);
  Serial.println("back");
  Serial.println("");
}

void leftMotion() {
  digitalWrite(3, 50);
  digitalWrite(5, HIGH);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  Serial.println("left");
  Serial.println("");
}

void rightMotion() {
  digitalWrite(3, HIGH);
  digitalWrite(5, 50);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  Serial.println("right");
  Serial.println("");
}

void flipMotion() {
  digitalWrite(3, 100);
  digitalWrite(5, LOW);
  digitalWrite(2, LOW);
  digitalWrite(4, LOW);
  Serial.println("flip");
  Serial.println("");
  delay(500);
}

void stopMotion() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  Serial.println("stop");
  Serial.println("");
}

void handMotion() {
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

