#include <VirtualWire.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
int x, y, z;
void setup(void)
{
  Serial.begin(9600);
  delay(10);
  if (!accel.begin())
  {
    Serial.println("Check your wiring!");
    while (1);
  }
}

void loop(void)
{

  sensors_event_t accelEvent;
  accel.getEvent(&accelEvent);
  //digitalWrite(int(accelEvent.acceleration.x), HIGH);
  x = int(accelEvent.acceleration.x);
  //  Serial.println(x);
  y = int(accelEvent.acceleration.y);
  //  Serial.println(y);
  z = int(accelEvent.acceleration.z);
  if (x > 4) {
    Serial.println("X Found");
  } if(x < -4){
    Serial.println("-X Found");
  } if (y > 4) {
    Serial.println("Y Found");
  } if(y < -4){
    Serial.println("-Y Found");
  } if (z > 4) {
    Serial.println("Z Found");
  }if(z < -4){
    Serial.println("-Z Found");
  }
  delay(500);
}
