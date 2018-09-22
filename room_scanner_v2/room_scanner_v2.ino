#include <LiquidCrystal.h>
#include <SoftwareSerial.h>;

//HC 05
SoftwareSerial bluetooth(0, 1); // RX, TX
int BluetoothData;

//HC SR-05
#define ECHOPIN 8        // Pin to receive echo pulse
#define TRIGPIN 9        // Pin to send trigger pulse

//LM-35
#define tempPin 0

//pir sensor
#define inputPin 10

// initialize the library with the numbers of the interface pins
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);

//lm35
int val;

//pir
int pirState = LOW; // we start, assuming no motion detected
int pirVal = 0; // variable for reading the pin status


void setup() {

  Serial.begin(9600);
  bluetooth.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("Powered BY:");
  lcd.setCursor(3, 1);
  lcd.print("Sabbir Ahmed");
  delay(500);
  lcd.clear();

  //HC SR-05
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
}

void loop() {
  if (bluetooth.available())
  {
    BluetoothData = bluetooth.read();

    if (BluetoothData == 't')
    {
      temp();
    }
    if (BluetoothData == 'd')
    {
      dist();
    }
  }
  pirVal = digitalRead(inputPin); // read input pirValue
  if (pirVal == HIGH) { // check if the input is HIGH

    if (pirState == LOW) {
      // we have just turned on
      lcd.clear();
      Serial.println("Motion detected!");
      temp();
      lcd.print("Motion detected!");
      dist();
      // We only want to print on the output change, not state
      pirState = HIGH;
    }
  } else {

    if (pirState == HIGH) {
      // we have just turned of
      lcd.clear();
      Serial.println("Motion detected!");
      lcd.print("Motion ended!");
      temp();
      dist();
      // We only want to print on the output change, not state
      pirState = LOW;
    }
  }
}

void temp() {
  //lm35 sensor
  val = analogRead(tempPin);
  float mv = ( val / 1024.0) * 5000;
  int cel = mv / 10;
  //farenhite
  //float farh = (cel * 9) / 5 + 32;
  lcd.setCursor(0, 1);
  lcd.print("T= ");
  lcd.print(cel);
  lcd.print("C");
  Serial.print("Temp= ");
  Serial.print(cel);
  Serial.println();
  delay(1000);
}

void dist()
{
  // Start Ranging -Generating a trigger of 10us burst
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  // Distance Calculation


  float distance = pulseIn(ECHOPIN, HIGH);
  distance = distance / 58.2;

  if (distance <= 30) {
    /* The speed of sound is 340 m/s or 29 us per cm.The Ultrasonic burst travels out & back.So to find the distance of object we divide by 58  */
    lcd.setCursor(6, 1);
    lcd.print(" | ");
    lcd.print(distance);
    lcd.print("cm");
    Serial.print(distance);
    Serial.println("cm");

  }
  else {
    dist_inch();
  }
  delay(200);
}

void dist_inch()
{
  // Start Ranging -Generating a trigger of 10us burst
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  // Distance Calculation


  float distance = pulseIn(ECHOPIN, HIGH);
  distance = distance / 148;

  /* The speed of sound is 340 m/s or 29 us per cm.The Ultrasonic burst travels out & back.So to find the distance of object we divide by 58  */
  lcd.setCursor(6, 1);
  lcd.print(" | ");
  lcd.print(distance);
  lcd.print("in");
  Serial.print(distance);
  Serial.println("in");

  delay(200);
}

