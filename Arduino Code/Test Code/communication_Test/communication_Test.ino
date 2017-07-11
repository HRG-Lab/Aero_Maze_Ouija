 
/*
 This code is for testing that two xbees can communicate with each other. Each teensy-xbee setup will have this code. The data taken from one serial monitor will be passed from it through the TX port connected to the XBEee and through the XBee connected to the RX port
 on the recieving setup. For this to work the XBees need to be on the same frequency, i.e. 7FFF. This code was written for teensy 3.0 and teensy LC, for other setups the Serial3 will need to be changed to reflect which TX and RX ports are being used.
 */
#include <XBee.h>
 
//https://learn.sparkfun.com/tutorials/teensy-xbee-adapter-hookup-guide
//Characters sent out the serial monitor go
// Out the UART1 TX pin -> onto the airwaves -> out the XBee serial terminal
//
//Be sure to select UART1 on the adapter board's switch for HW serial
 XBee xbee = XBee();
void setup()
{
  //Begin serial monitor port
  Serial.begin(9600);
  //Begin HW serial
  Serial3.begin(9600);
  //stuff that I don’t understand
  xbee.setSerial(Serial3);
}
 
void loop()
{
  // Take data received from the serial monitor and pass it to the HW UART
  if(Serial.available())
  {
    Serial3.print(Serial.read(), BYTE);
  }
 
  // Take data received from the HW UART and pass it to the serial monitor
  if(Serial3.available())
  {
    Serial.println(Serial3.read(), BYTE);
  }
 
  //Wait to reduce serial load
  delay(5);
}
//
 
 
 

