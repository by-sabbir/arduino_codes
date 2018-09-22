//HC SR-05
#define ECHOPIN 8        // Pin to receive echo pulse
#define TRIGPIN 9        // Pin to send trigger pulse
#define buzzpin 10

float dist_cm;
void setup() {
  //HC SR-05
  Serial.begin(9600);
  pinMode(ECHOPIN, INPUT);
  pinMode(TRIGPIN, OUTPUT);
  pinMode(buzzpin, OUTPUT);
}

void loop() {
  // Start Ranging -Generating a trigger of 10us burst
  digitalWrite(TRIGPIN, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIGPIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIGPIN, LOW);

  // Distance Calculation
  float distance = pulseIn(ECHOPIN, HIGH);
  distance = distance / 58.2;
  Serial.println(distance);
  if (distance <= 20) {
    digitalWrite(buzzpin, HIGH);
  }
  if (distance > 20){
    digitalWrite(buzzpin, LOW);
  }
}
