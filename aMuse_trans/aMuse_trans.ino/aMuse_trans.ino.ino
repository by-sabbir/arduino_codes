#include <VirtualWire.h>
#include <Wire.h>
#include <Adafruit_Sensor.h>
#include <Adafruit_ADXL345_U.h>
Adafruit_ADXL345_Unified accel = Adafruit_ADXL345_Unified(12345);
int dataX, dataY, dataZ;

// RF Send
char msg;

void setup() {
  Serial.begin(9600);
  delay(10);
  vw_set_tx_pin(6);          // Sets pin D12 as the TX pin
  vw_setup(2000);          // Bits per sec

  if (!accel.begin()) {
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
  if (dataX > 4 && dataY < 5) {
    Serial.print("n");
    msg = "n";
    vw_send((uint8_t *)msg, strlen(msg)); //transmits the data
    vw_wait_tx(); // Wait until the whole message is gone
    delay(50);
  }

  //Playing Previous
  if (dataX < -3 && dataY < 5) {
    Serial.print("p");
    msg = "p";
    vw_send((uint8_t *)msg, strlen(msg)); //transmits the data
    vw_wait_tx(); // Wait until the whole message is gone
    delay(50);
  }
  //Volume Down
  if (dataY > 3 && dataX < 5) {
    Serial.print("+");
    msg = "+";
    vw_send((uint8_t *)msg, strlen(msg)); //transmits the data
    vw_wait_tx(); // Wait until the whole message is gone
    delay(50);
  }
  //Volume Up
  if (dataY < -3 && dataX < 5) {
    Serial.print("-");
    msg = "-";
    vw_send((uint8_t *)msg, strlen(msg)); //transmits the data
    vw_wait_tx(); // Wait until the whole message is gone
    delay(50);
  }
  Serial.println();
  delay(500);
}
