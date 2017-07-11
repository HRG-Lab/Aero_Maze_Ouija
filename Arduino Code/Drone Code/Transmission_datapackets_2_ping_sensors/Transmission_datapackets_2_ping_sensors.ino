//LINK for the EasyTranfer library download: 
//http://www.billporter.info/2011/05/30/easytransfer-arduino-library/
//     for easy data tranfer using packets

#include <EasyTransfer.h>

const int pingPin1 = 14;
const int pingPin2 = 15;
float duration1, duration2;

EasyTransfer ET; //creates object

struct SEND_DATA {   //puts all the variables inside a struct to send a packet of data
  char id='b';
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
  duration2 = getDuration(pingPin2);
  data.cm = microsecondsToCentimeters(duration1); //1st sensor distance value
  //data.cm2 = microsecondsToCentimeters(duration2); //2nd sensor distance value
  
  //send the data
  ET.sendData();

  //printing the data to my serial monitor
  Serial.print(data.cm);
  Serial.print(", ");
 // Serial.println(data.cm2);

  //printing data to the other serial monitor on the recieving end
  Serial3.print(data.cm);
  Serial3.print(", ");
  //Serial3.println(data.cm2);

  delay(250); // Wait to reduce serial load
}
