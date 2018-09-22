#include <SPI.h>
#include <RFID.h>
 
#define SS_PIN 10
#define RST_PIN 9

RFID rfid(SS_PIN,RST_PIN);

void setup(){
  Serial.begin(9600);
  SPI.begin();
  rfid.init();
}

void loop(){
  byte i;
  if(rfid.isCard()){
    rfid.readCardSerial();
    Serial.println("Card Detected");

    for(i=0; i<=4; i++){
      Serial.print(rfid.serNum[i]);
      Serial.print(" ");
    }
  }
  Serial.flush();       
}

