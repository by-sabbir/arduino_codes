
#include <SPI.h>
#include <MFRC522.h>
#include "Keyboard.h"

#define SS_PIN 10
#define RST_PIN 9

MFRC522 rfid(SS_PIN, RST_PIN); 

MFRC522::MIFARE_Key key;


//Leonardo Var
char ctrlKey = KEY_LEFT_CTRL;
char altKey =  KEY_LEFT_ALT;


byte nuidPICC[4];
byte knownTac[4] = {100, 255, 015, 187};
boolean KNOW = true;

void setup() {
  Serial.begin(9600);
  SPI.begin();
  Keyboard.begin();
  rfid.PCD_Init();

  for (byte i = 0; i < 6; i++) {
    key.keyByte[i] = 0xFF;
  }
}

void loop() {


  if ( ! rfid.PICC_IsNewCardPresent())
    return;

  if ( ! rfid.PICC_ReadCardSerial())
    return;

  MFRC522::PICC_Type piccType = rfid.PICC_GetType(rfid.uid.sak);

  // Check is the PICC of Classic MIFARE type
  if (piccType != MFRC522::PICC_TYPE_MIFARE_MINI &&
      piccType != MFRC522::PICC_TYPE_MIFARE_1K &&
      piccType != MFRC522::PICC_TYPE_MIFARE_4K) {
    //Serial.println(F("Your tag is not of type MIFARE Classic."));
    return;
  }

  if (rfid.uid.uidByte[0] != nuidPICC[0] ||
      rfid.uid.uidByte[1] != nuidPICC[1] ||
      rfid.uid.uidByte[2] != nuidPICC[2] ||
      rfid.uid.uidByte[3] != nuidPICC[3] ) {

    for (byte i = 0; i < 4; i++) {
      nuidPICC[i] = rfid.uid.uidByte[i];
    }
    
    printDec(rfid.uid.uidByte, rfid.uid.size);
    Serial.println();

    for (int i = 0; i < 4; i++) {
      if (knownTac[i] != nuidPICC[i]) {
        KNOW = false;
      } else {
        KNOW = true;
      }
    }

  }
  else

  rfid.PICC_HaltA();

  rfid.PCD_StopCrypto1();

  if (KNOW) {
    Keyboard.press('1');
    delay(10);
    Keyboard.press('9');
    delay(10);
    Keyboard.press(KEY_RETURN);
    Keyboard.releaseAll();
    delay(500);
    Serial.print("Logged in...");
  } else {
    Keyboard.press(ctrlKey);
    delay(10);
    Keyboard.press(altKey);
    delay(10);
    Keyboard.press('l');
    delay(10);
    Keyboard.releaseAll();
    delay(500);
    Serial.print("Logged out...");
  }
}


/**
   Helper routine to dump a byte array as hex values to Serial.

void printHex(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], HEX);
  }
}
*/


/**
   Helper routine to dump a byte array as dec values to Serial.
*/
void printDec(byte *buffer, byte bufferSize) {
  for (byte i = 0; i < bufferSize; i++) {
    Serial.print(buffer[i] < 0x10 ? " 0" : " ");
    Serial.print(buffer[i], DEC);
  }
}
