int buttonState = 0;
const int buttonPin = 2; 

void setup() {
  pinMode(2,INPUT);
  Serial.begin(9600);
}

void loop() {
  buttonState = digitalRead(buttonPin);
  Serial.println(buttonState);
  buttonState=0;
  Serial.println(buttonState);
  
}
