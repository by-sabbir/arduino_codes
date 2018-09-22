//load libraries
#include <VirtualWire.h>
int i,j;    //and integer used to count

void setup()
{   
    //Define the receiver pin and rate
    Serial.begin(9600);
    vw_set_rx_pin(8);       //Sets pin D12 as the RX Pin
    vw_setup(2000);       // Bits per sec
    vw_rx_start();           // Start the receiver PLL running
}

void loop()
{
   uint8_t buf[VW_MAX_MESSAGE_LEN];
   uint8_t buflen = VW_MAX_MESSAGE_LEN;
   
   if( vw_get_message(buf, &buflen) )
      {
          
        
       for (i = 0; i < buflen; i++)
         { 
           Serial.write(buf[i]); 
                    
         }
          
           Serial.println(((int)i));
      }
 
}

