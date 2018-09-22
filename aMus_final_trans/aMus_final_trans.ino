 #include <VirtualWire.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
int x, y, z;

void setup() {
  Serial.begin(9600);
  vw_set_tx_pin(13);          // Sets pin D12 as the TX pin
  vw_setup(2000);          // Bits per sec
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
  x = int(accelEvent.acceleration.x);
  //  Serial.println(x);
  y = int(accelEvent.acceleration.y);
  //  Serial.println(y);
  z = int(accelEvent.acceleration.z);
  if (x > 4) {
    Serial.println("X Found");
    sendRf("X");
  } if(x < -4){
    Serial.println("-X Found");
    sendRf("x");
  } if (y > 4) {
    Serial.println("Y Found");
    sendRf("Y");
  } if(y < -4){
    Serial.println("-Y Found");
    sendRf("y");
  } if (z > 4) {
    Serial.println("Z Found");
    sendRf("Z");
  }if(z < -4){
    Serial.println("-Z Found");
    sendRf("z");
  }
  delay(80);
}

void sendRf(char msg[1]) {
  vw_send((uint8_t *)msg, strlen(msg));
  vw_wait_tx();
  delay(50);
  Serial.print(msg);
}

