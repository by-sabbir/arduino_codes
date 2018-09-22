#include <VirtualWire.h>
int i;    //and integer used to count
char data;
void setup()
{
  pinMode(7, OUTPUT);
  //Define the receiver pin and rate
  Serial.begin(9600);
  vw_set_rx_pin(9 );       //Sets pin D12 as the RX Pin
  vw_setup(2000);       // Bits per sec
  vw_rx_start();           // Start the receiver PLL running
  Serial.println("Recieving String");
}

void loop()
{
  uint8_t buf[VW_MAX_MESSAGE_LEN];
  uint8_t buflen = VW_MAX_MESSAGE_LEN;

  if ( vw_get_message(buf, &buflen) )
  {


    for (i = 0; i < buflen; i++)
    {
      //      Serial.print(char(buf[i]));
      data = char(buf[i]);
      if (data == 'Z') {
        Serial.print("stable");
      } if (data == 'z') {
        Serial.print("next");
      } if (data == 'y') {
        Serial.print("skip_nxt");
      } if (data == 'Y') {
        Serial.print("skip_prev");
      } if (data == 'X') {
        Serial.print("vol_up");
      } if (data == 'x') {
        Serial.print("vol_down");
      }
    }
    Serial.flush();
    Serial.println();
  }

}

