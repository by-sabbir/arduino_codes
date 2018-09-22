#include <SoftwareSerial.h>

SoftwareSerial esp(2, 3); // 0-Rx, 1-Tx

void setup() {
  Serial.begin(9600);
  esp.begin(9600);
}

void loop() {
  if (esp.available()){
    while(esp.available()){
      char c = esp.read();
      Serial.write(c);
    }
  }

  if(Serial.available()){
    delay(300);
    String cmd="";
    while(Serial.available()){
      cmd += (char)Serial.read();
    }
    esp.println(cmd);
  }
}
