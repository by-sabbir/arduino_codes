#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>

Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);

int x, y, z;
void setup(void)
{
  Serial.begin(9600);
  Serial.println("ADXL345 Accelerometer Calibration");
  Serial.println("");

  /* Initialise the sensor */
  if (!accel.begin())
  {
    /* There was a problem detecting the ADXL345 ... check your connections */
    Serial.println("Ooops, no ADXL345 detected ... Check your wiring!");
    while (1);
  }
}

void loop()
{

  sensors_event_t accelEvent;
  accel.getEvent(&accelEvent);
  //digitalWrite(int(accelEvent.acceleration.x), HIGH);
  x = int(accelEvent.acceleration.x);
//  Serial.println(x);
  y = int(accelEvent.acceleration.y);
//  Serial.println(y);
  z = int(accelEvent.acceleration.z);
  Serial.println(z);
  delay(500);
}
