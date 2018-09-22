#define face 7
#define eye 8
#define alart 6

int t2 = 0, t1 = 0, t = 0;
char data;
void setup() {
  pinMode(face, OUTPUT);
  pinMode(eye, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    digitalWrite(eye, LOW);
    digitalWrite(alart, LOW);
    digitalWrite(face, LOW);
    data = Serial.read();
    if (data == 'f') {
      digitalWrite(face, HIGH);
    if (data == 'e') {
      digitalWrite(eye, HIGH);
    }
    else {
      digitalWrite(alart, HIGH);
    }
    }
    else{
        //asd
    }
    
  }
}
