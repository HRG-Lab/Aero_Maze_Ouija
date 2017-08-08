/*
This is for transmitting data through the Easy Transfer Library to the flying maze. The distance is measured from the ultrasonic sensor and sent through the XBee.  The distance equation is for  the XL -MaxSonar -EZ/AE sensor. For different types of sensors a new 
calibtration equation needs to be derived. This code was written for Teensy 3.0 and Teensy LC. Other versions of Teensy or Arduino may require the Serial3 to be changed. 
*/

#include <EasyTransfer.h>

const int pingPin = 14;
float val = 0; 
// variable to store the values from sensor(initially zero)

EasyTransfer ET; //creates object

struct SEND_DATA {   //puts all the variables inside a struct to send a packet of data
  char id='e';
  float cm; 
};

SEND_DATA data; //creates a variable that i can use in loop

void setup()
{
  Serial.begin(9600);               // starts the serial monitor
  Serial3.begin(9600);
  ET.begin(details(data), &Serial3); //opens serial port between the xbees
}
 
void loop()
{
  val = analogRead(pingPin); // reads the value of the sharp sensor
  //float a = pow(val,-1.125);
  data.cm = (.6869*val)+2;//-2.434; //(0.6869*val)-2.434; distance equation
  Serial.println(data.cm);            // prints the value of the sensor to the serial monitor

  //send the data
  ET.sendData();

  //Serial3.println(data.cm);
  delay(250);                    // wait for this much time before printing next value
}
