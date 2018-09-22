/*
  Robot Auto - Remote car receives joystick values from MX-FS-03V transmitter to the XY-MK-5V receiver
*/

// download library van http://www.pjrc.com/teensy/td_libs_VirtualWire.html
#include <VirtualWire.h>

const int receive_pin = 6;

bool test = true;

// save values
int Hval, Vval, Kval;

unsigned int gebruiker = 2000 * 0;

void setup() {
  // Begin Seriele monitor
  Serial.begin(9600);

  vw_set_rx_pin(receive_pin);
  vw_setup(2000);

  // Start the receiver PLL running
  vw_rx_start();

  //startwaarden joystick
  Hval = 0;
  Vval = 0;
  Kval = 1;
}

void loop() {
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;
  uint16_t tmp_Hval, tmp_Vval, tmp_Kval;

  // non blocking, read values when processed
  if (vw_get_message(buf, &buflen)) { // Non-blocking
    // Message with a good checksum received, print it.

    Serial.print("Got: ");
    for (int i = 0; i < buflen; i++) {
      Serial.print(buf[i], HEX);
      Serial.print(' ');
    }
    Serial.println();

    //uint8 received, convert to normal uint16:
    if (buflen == 6)  {
      tmp_Hval =  buf[0]; tmp_Hval = (tmp_Hval << 8) +  buf[1];
      tmp_Vval =  buf[2]; tmp_Vval = (tmp_Vval << 8) +  buf[3];
      tmp_Kval =  buf[4]; tmp_Kval = (tmp_Kval << 8) +  buf[5];

      // discrimate between cars using the gebruiker varible. Sensor values are 0 to 1024
      if (tmp_Hval >= gebruiker && tmp_Hval < gebruiker + 1025 &&
          tmp_Vval >= gebruiker && tmp_Vval < gebruiker + 1025 &&
          tmp_Kval >= gebruiker && tmp_Kval < gebruiker + 1025 ) {
        // waarden van de juiste gebruiker !
        Hval = tmp_Hval - gebruiker;
        Vval = tmp_Vval - gebruiker;
        Kval = tmp_Kval - gebruiker; // zal 0 of 1 zijn

        Serial.print("Computed received values: ");
        toonWaarden();

      } else {
        if (test) {
          Serial.print("Problem, Converted to: ");
          Serial.print ("  ");
          Serial.print (tmp_Hval);
          Serial.print ("  --  ");
          Serial.print (tmp_Vval);
          Serial.print ("  --  ");
          Serial.print (tmp_Kval);
          Serial.print ("  --  ");
          Serial.print ((unsigned int) buf[0]);
          Serial.print ("  --  ");
          Serial.print ((unsigned int) buf[1]);
          Serial.print ("  --  ");
          Serial.print ((unsigned int) buf[4]);
          Serial.print ("  --  ");
          Serial.print ((unsigned int) buf[5]);
          Serial.println ("  --");
        }
      }
    } else {
      Serial.println("Error, buffer of wrong length received!");
    }
  }
}

void toonWaarden() {
  Serial.print ("  ");
  Serial.print (Hval);
  Serial.print ("  --  ");
  Serial.print (Vval);
  Serial.print ("  --  ");
  Serial.print (Kval);
  Serial.println ("  --");
}
