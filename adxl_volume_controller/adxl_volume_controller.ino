#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
int dataX, dataY, dataZ;

void setup() {
  Serial.begin(9600);
  delay(10);
  if (!accel.begin())
  {
    Serial.println("Check your wiring!");
    while (1);
  }
}

void loop() {
  sensors_event_t accelEvent;
  accel.getEvent(&accelEvent);
  //digitalWrite(int(accelEvent.acceleration.x), HIGH);
  dataX = int(accelEvent.acceleration.x);
  dataY = int(accelEvent.acceleration.y);
  
  //Playing Next
  if (dataX > 4 && dataY < 5){
    Serial.print("n");
  }
  
  //Playing Previous
  if (dataX < -3 && dataY < 5){
    Serial.print("p");
  }
  //Volume Down
  if(dataY > 3 && dataX < 5){
    Serial.print("+");
  }
  //Volume Up
  if(dataY < -3 && dataX < 5){
    Serial.print("-");
  }
  Serial.println();
  delay(500);
}
