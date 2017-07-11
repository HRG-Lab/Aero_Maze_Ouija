

/*
Coded by Marjan Olesch
Sketch from Insctructables.com
Open source - do what you want with this code!
*/
#include <Servo.h>


int futureVal, currVal; // set values you need to zero

Servo firstESC; //Create as much as Servoobject you want. You can controll 2 or more Servos at the same time

void setup() {
  firstESC.attach(9);    // attached to pin 9 I just do this with 1 Servo
 // secondESC.attach(6);
   Serial.begin(9600);   // start serial at 9600 baud
  currVal=0; 
  firstESC.writeMicroseconds(currVal);
 // secondESC.writeMicroseconds(value);
  Serial.println(currVal);
  delayMicroseconds(3000000);
  currVal=500;
  firstESC.writeMicroseconds(currVal);
 // secondESC.writeMicroseconds(value);
  Serial.println(currVal);
  delayMicroseconds(3000000);
  futureVal = 500;
}


void increaseMotorSpeed() {
  while(currVal != futureVal) {
    if (currVal < futureVal) {
      currVal++;
    }
    else {
      currVal--;
    }
    firstESC.writeMicroseconds(currVal);
    Serial.println("Hey");
    delayMicroseconds(100);
  }
}

void loop() {

  while(currVal != futureVal) {
    if (currVal < futureVal) {
      currVal++;
    }
    else {
      currVal--;
    }
    firstESC.writeMicroseconds(currVal);
    Serial.println(currVal);
    delayMicroseconds(25000);
  }
  
  while (Serial.available()) {
    futureVal = Serial.parseInt();
  }
    delayMicroseconds(100000);
    Serial.println(currVal);
}


