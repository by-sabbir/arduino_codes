
#include <VirtualWire.h> //Load the library

int temp,mapped;        //Define the temp float variable
int sensor = 0;     // sensor middle pin on analog pin 0
char msg[6];


void setup()
{
    Serial.begin(9600);
    vw_set_tx_pin(9);          // Sets pin D12 as the TX pin
    vw_setup(2000);          // Bits per sec
}

void loop()
{        //assigning the analog output to temp
      mapped = 10;
      Serial.println(mapped);
      dtostrf(mapped, 6,2,msg);           //converts the float into a char 
      vw_send((uint8_t *)msg, strlen(msg)); //transmits the data
      vw_wait_tx(); // Wait until the whole message is gone
      delay(50);
    //}
 }
 

