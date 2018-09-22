/*
 *        Programmed By: Sabbir Ahmed
 *                       EEE-14, HSTU.
 *            Foudner & President: Alpha Tech
 *            GS: EEE-Club, HSTU. 
 *            Connect Me: sabbir.eee.hstu@gmail.com
 */

#include <Servo.h>
#define ECHOPIN 7
#define TRIGPIN 8

Servo myServo;

int pos = 90, movingAngle;

float angles[181], maxDist;

void setup() {
  Serial.begin(9600);
  myServo.attach(5);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);

}

void loop() {
  if (dist() > 35) {
    forwardMotion();
  }
  if (dist() <= 35) {
    stopMotion();
    Serial.println("");
    Serial.println("*****************************");
    Serial.println("Mapping Angle: ");
    for (pos = 0 ; pos <= 180 ; pos += 45) {
      myServo.write(pos);
      
      Serial.println(pos);
      angles[pos] = dist();
      Serial.print("Distance in this Angle:   ");
      Serial.println(angles[pos]);
      delay(1000);
    }

    maxDist = angles[0];
    
    for (pos = 0; pos < 181; pos += 45) {

      if (angles[pos] > maxDist) {
        maxDist = angles[pos];
        movingAngle = pos;
        Serial.println("");
        Serial.println("*****************************");
        Serial.print("Angle Selected: ");
        Serial.println(movingAngle);
        Serial.println("*****************************");
        Serial.println("");
        Serial.println("");
      }
    }
    if (movingAngle == 0) {
      myServo.write(90);
      hardRightMotion();
    }
    if (movingAngle == 45) {
      myServo.write(90);
      rightMotion();
    }
    if (movingAngle == 90) {
      myServo.write(90);
      forwardMotion();
    }
    if (movingAngle == 135) {
      myServo.write(90);
      leftMotion();
    }
    if (movingAngle == 180) {
      myServo.write(90);
      hardLeftMotion();
    }
  }
}

/*
 * void verticalScan() {
  for (pos = 45; pos <= 135; pos += 45) {
    myServo.write(pos);
    Serial.println(pso);
    angles[pos] = dist();
    Serial.print("Distance in this Angle:   ");
    Serial.println(angles[pos]);
    delay(1000);
  }
  maxDist = angles[45];

  for(pos = 45; pos <= 135; pos += 45){
    if(angles[pos] > maxDist){
      maxDist = angles[pos];
      movingAngle = pos;
    }
  }
}

 */

float dist() {

  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);
  // Distance Calculation

  float distance = pulseIn(ECHOPIN, HIGH);
  distance = distance / 58.2;
  //Serial.println(distance);
  return (distance);
}

void forwardMotion() {
  digitalWrite(2, HIGH);
  digitalWrite(4, HIGH);
  Serial.println("");
  Serial.println("*****************************");
  Serial.println("");
  Serial.println("forwardMotion Started");
  Serial.println("");
  Serial.println("*****************************");
}

void rightMotion() {
  digitalWrite(2, HIGH);
  digitalWrite(4, LOW);
  Serial.println("");
  Serial.println("*****************************");
  Serial.println("");
  Serial.println("rightMotion Started");
  Serial.println("");
  Serial.println("*****************************");
}

void leftMotion() {
  digitalWrite(2, LOW);
  digitalWrite(4, HIGH);
  Serial.println("");
  Serial.println("*****************************");
  Serial.println("");
  Serial.println("leftMotion Started");
  Serial.println("");
  Serial.println("*****************************");
}

void hardRightMotion() {
  digitalWrite(2, HIGH);
  digitalWrite(5, HIGH);
  Serial.println("");
  Serial.println("*****************************");
  Serial.println("");
  Serial.println("hardRightMotion Started");
  Serial.println("");
  Serial.println("*****************************");
}

void hardLeftMotion() {
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  Serial.println("");
  Serial.println("*****************************");
  Serial.println("");
  Serial.println("hardLeftMotion Started");
  Serial.println("");
  Serial.println("*****************************");
}

void backwardMotion() {
  digitalWrite(3, HIGH);
  digitalWrite(5, HIGH);
  Serial.println("");
  Serial.println("*****************************");
  Serial.println("");
  Serial.println("backwardMotion Started");
  Serial.println("");
  Serial.println("*****************************");
}


void stopMotion() {
  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, LOW);
  digitalWrite(5, LOW);
  Serial.println("");
  Serial.println("*****************************");
  Serial.println("");
  Serial.println("Stopped all Motion");
  Serial.println("");
  Serial.println("*****************************");
}
