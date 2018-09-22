/*

             By-Alpha Tech
          Dept. of EEE-14,HSTU.

*/

#include <LiquidCrystal.h>
#include <SoftwareSerial.h>;
#include<Servo.h>

//motion tracker
int inputPin = 2; // choose the input pin (for PIR sensor)
int pirState = LOW; // we start, assuming no motion detected
int pirVal = 0; // variable for reading the pin status

//distacne tracker config
#define ECHOPIN 7        // Pin to receive echo pulse
#define TRIGPIN 8        // Pin to send trigger pulse

//lcd config
LiquidCrystal lcd0(42, 44, 46, 48, 50, 52);
LiquidCrystal lcd1(43, 45, 47, 49, 51, 53);

//bluetooth config
SoftwareSerial bluetooth(0, 1); // RX, TX
int bluetoothData;

//servo config
Servo ms;

//LM35 config
int val;
int tempPin = 0;

void setup() {

  Serial.begin(9600);

  //PIR setup
  pinMode(inputPin, INPUT); // declare sensor as input

  //distance tracker setup
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);

  //lcd setup
  lcd0.begin(16, 2);
  lcd1.begin(16, 2);

  //servo setup
  ms.attach(6);

}

void loop() {

  while (bluetooth.available())
  {
    BluetoothData = bluetooth.read();
    
    if (BluetoothData == '0')
    {
      //condition
    }

}

void dist() {
  // Start Ranging -Generating a trigger of 10us burst
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  // Distance Calculation

  float distance = pulseIn(ECHOPIN, HIGH);
  distance = distance / 58.2;
  Serial.print(distance);
  Serial.println(" cm");
}

void temp() {
  val = analogRead(tempPin);
  float mv = ( val / 1024.0) * 5000;
  float cel = mv / 10;
  float farh = (cel * 9) / 5 + 32;

  Serial.print("TEMPRATURE = ");
  Serial.print(cel);
  Serial.print("*C");
  Serial.println();
  delay(1000);

  /* uncomment this to get temperature in farenhite
    Serial.print("TEMPRATURE = ");
    Serial.print(farh);
    Serial.print("*F");
    Serial.println();


  */
}

void motion() {

  pirVal = digitalRead(inputPin); // read input pirValue
  if (pirVal == HIGH) { // check if the input is HIGH
    if (pirState == LOW) {
      // we have just turned on
      Serial.println("Motion detected!");
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {
    if (pirState == HIGH) {
      // we have just turned off
      Serial.println("Motion ended!");
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }

}

void alarm() {

}
