char data[] = "I am Keyboard";
void setup() {
  Serial.begin(9600);
  Serial.println(data);
}

void loop() {
  delay(1000);
  writeIn(data);
}

void writeIn(char text[]) {
  int i, len;
  len = strlen(text);
  //  Serial.println(text);
  for (i = 0; i < len; i++) {
    Serial.print(text[i]);
    delay(210);
  }
  Serial.println();
}

