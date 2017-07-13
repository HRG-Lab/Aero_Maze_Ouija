/*
This is for transmitting data through the Easy Transfer Library to the flying maze. The distance is measured from the ultrasonic sensor and sent through the XBee.  The microseconstocentimeters function and getduration were written for the Parallax 28015 REV B ultrasonic
sensor. This code was written for Teensy 3.0 and Teensy LC. Other versions of Teensy or Arduino may require the 
Serial3 to be changed. 
*/

//LINK for the EasyTranfer library download: 
//http://www.billporter.info/2011/05/30/easytransfer-arduino-library/
//     for easy data tranfer using packets

#include <EasyTransfer.h>

const int pingPin1 = 14;
float duration1;

EasyTransfer ET; //creates object

struct SEND_DATA {   //puts all the variables inside a struct to send a packet of data
<<<<<<< HEAD
  char id='d';//change this character based on which sending setup this code is loaded on a-b-c-d-e-f 
=======
  char id='e';//change this character based on which sending setup this code is loaded on a-b-c-d-e-f 
>>>>>>> 88ebf8c02d49557ea83166c37c8dd9138d93c9c3
  float cm; 
};

SEND_DATA data; //creates a variable that i can use in loop

void setup()
{
  //Begin serial monitor port on transmitting end
  Serial.begin(9600);
  Serial3.begin(9600);
  //Begin HW serial
  ET.begin(details(data), &Serial3); //opens serial port between the xbees
}

float microsecondsToCentimeters(float microseconds) {
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

float getDuration(int pingPin)
{
  //Code to read in the Ping sensor value
  pinMode(pingPin, OUTPUT);
  digitalWrite(pingPin, LOW);
  delayMicroseconds(2);
  digitalWrite(pingPin, HIGH);
  delayMicroseconds(5);
  digitalWrite(pingPin, LOW);
  pinMode(pingPin, INPUT);
  
  float duration = pulseIn(pingPin,HIGH);
  return duration;
}
void loop() {
  // put your main code here, to run repeatedly:
  // Take data received from the serial monitor and pass it to the HW UART 
  duration1 = getDuration(pingPin1);
  data.cm = microsecondsToCentimeters(duration1); //1st sensor distance value
  
  //send the data
  ET.sendData();

  //printing the data to my serial monitor
  Serial.print(data.cm);
  Serial.print(", ");

  //printing data to the other serial monitor on the recieving end
  //Serial3.print(data.cm); //This line is not needed since EasyTransfer library is being used
  
  delay(250); // Wait to reduce serial load
}
