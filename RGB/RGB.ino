int r = 7, g = 8, b = 9;
int red, green, blue;
void setup() {
  pinMode(r, OUTPUT);
  pinMode(g, OUTPUT);
  pinMode(b, OUTPUT);
  Serial.begin(9600);
  delay(20);
}

void loop() {
  // RED
  digitalWrite(r, LOW);
  red = analogRead(0);
  delay(100);
  digitalWrite(r, HIGH);
  delay(50);
  // GREEN
  digitalWrite(g, LOW);
  green = analogRead(0);
  delay(100);
  digitalWrite(g, HIGH);
  delay(50);
  // BLUE
  digitalWrite(b, LOW);
  blue = analogRead(0);
  delay(100);
  digitalWrite(b, HIGH);
  delay(50);
  Serial.print(red);  Serial.print(", ");
  Serial.print(green);  Serial.print(", ");
  Serial.print(blue);  Serial.print(", ");
  Serial.println();
  delay(50);
  minimum();
}

void minimum(){
  if(red < blue){
    if (red< green){
      Serial.println("RED");
    }
    else{
      Serial.println("NOT RED");
    }
  }
}

