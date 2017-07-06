/*
 This code is for the recieving structure that controls all six motors attached to the body of the flying maze. The motors are initialized and throttled in the setup procedure. A data stucture called "data" is recieved containing an identifying character "data.id" and
 distance "data.cm" from each ultrasonic sensor setup. If the distance is less than 80cm it will turn the motor on, increasing motor rpm until it reaches 5cm. If the distance recieved is not less than 80cm or is 0cm the motor will have a default value written to it that 
 puts it in the "off" state. The code was written for the Teensy 3.0 and Teensy LC. For different versions of Teensy and Arduino the Serial3 port may need to be changed.
 */
#include <Servo.h>
#include <EasyTransfer.h>
#include <XBee.h>

//create object
Servo esc;
Servo esc2;
Servo esc3;
Servo esc4;
Servo esc5;
Servo esc6;
XBee xbee = XBee();
EasyTransfer ET; 
int value;
int dist_low=5;//lower bound of distance: declared for all motors. Change depending where you want your lower bound to be
int dist_high=80;//upper bound of distance: declared for all motors. Change depending where you want your upper bound to be
int motor_low=1300;//lower bound of motor speed: declared for all motors. Change depending where the motor turn on point is
int motor_high=1500;//upper bound of motor speed: declared for all motors. Change depending where the motor max speed is
int val_default=700;//default motor speed for off: declared for all motors. Change as needed to value that motor is not on yet. 0 does not work for this
//Rx16Response rx16 = Rx16Response();

//recieved data structure is from each sensor transmission setup, including an identifying character
//a-b-c-d-e-f and the distance
struct RECEIVE_DATA_STRUCTURE{
  //put your variable definitions here for the data you want to receive
  //THIS MUST BE EXACTLY THE SAME ON THE OTHER ARDUINO
  char id;
  float cm;
};


RECEIVE_DATA_STRUCTURE data;

void setup(){
  Serial.begin(9600);
  Serial3.begin(9600);
  xbee.setSerial(Serial3);
  xbee.begin(Serial3);
  //follwing lines are for setting up the motors
  esc.attach(2); //Specify the esc signal pin,Here as D8
  esc2.attach(3);
  esc3.attach(4);
  esc4.attach(5);
  esc5.attach(6);
  esc6.attach(9);
  value=0; 
  esc.writeMicroseconds(value);
  esc2.writeMicroseconds(value);
  esc3.writeMicroseconds(value);
  esc4.writeMicroseconds(value);
  esc5.writeMicroseconds(value);
  esc6.writeMicroseconds(value);
  //Serial.println(value);
  delayMicroseconds(500000);
  value=val_default;
  esc.writeMicroseconds(value);
  esc2.writeMicroseconds(value);
  esc3.writeMicroseconds(value);
  esc4.writeMicroseconds(value);
  esc5.writeMicroseconds(value);
  esc6.writeMicroseconds(value);
  //Serial.println(value);
  delayMicroseconds(500000);
  
  
  //start the library, pass in the data details and the name of the serial port. Can be Serial, Serial1, Serial2, etc. 
  ET.begin(details(data), &Serial3);
  //pinMode(13, OUTPUT);
  
}
float val,  rssi1;
float val2, rssi2;
float val3, rssi3;
float val4, rssi4;
float val5, rssi5;
float val6, rssi6;
float data1=0;
float data2=0;
float data3=0;
float data4=0;
float data5=0;
float data6=0;
void loop(){
  //check and see if a data packet has come in.
  //each case controls a single motor dependent on the recieved "id" character in the recieved data struct "data"
  //the motors will turn on when the distance sensed is less than 80
  if(ET.receiveData()){
      switch (data.id){
        /*************************************************************************************************************************/
        case 'a':
        data1=data.cm;
        if (data.cm<=80&&data.cm!=0){
          val= map(data.cm, dist_low, dist_high,motor_high,motor_low); //mapping val to minimum and maximum(Change if needed) 
        }
        else{
          val=val_default;
        }
        //Serial.println(val);
        esc.writeMicroseconds(val);
        break;
        /****************************************************************************************************************************/
        case 'b':
        data2=data.cm;
        if (data.cm<=80&&data.cm!=0){
       val2= map(data.cm, dist_low, dist_high,motor_high,motor_low); //mapping val to minimum and maximum(Change if needed) 
       }
        else{
        val2=val_default;
        }
        esc2.writeMicroseconds(val2);
        break;
        /**********************************************************************************************************************************/
        case 'c':
        data3=data.cm;
        if (data.cm<=80&&data.cm!=0){
       val3= map(data.cm, dist_low, dist_high,motor_high,motor_low); //mapping val to minimum and maximum(Change if needed) 
       }
        else{
        val3=val_default;
        }
        esc3.writeMicroseconds(val3);
        break;
        /**********************************************************************************************************************************/
        case 'd':
        data4=data.cm;
        if (data.cm<=80&&data.cm!=0){
          val4= map(data.cm, dist_low, dist_high,motor_high,motor_low); //mapping val to minimum and maximum(Change if needed) 
        }
        else{
          val4=val_default;
        }
        //Serial.println(val);
        esc4.writeMicroseconds(val4);
        break;
        /******************************************************************************************/
        case 'e':
        data5=data.cm;
        //rssi5=-20*log(t)/log(10);
        if (data.cm<=80&&data.cm!=0){
       val5= map(data.cm, dist_low, dist_high,motor_high,motor_low); //mapping val to minimum and maximum(Change if needed) 
       }
        else{
        val5=val_default;
        }
        esc5.writeMicroseconds(val5);
        break;
        /**********************************************************************************************************************************/
        case 'f':
        data6=data.cm;
        if (data.cm<=80&&data.cm!=0){
       val6= map(data.cm, dist_low, dist_high,motor_high,motor_low); //mapping val to minimum and maximum(Change if needed) 
       }
        else{
        val6=val_default;
        }
        esc6.writeMicroseconds(val6);
        break;
        /**********************************************************************************************************************************/     
}
Serial.print("A=");
Serial.print(data1);
Serial.print(" B=");
Serial.print(data2);
Serial.print(" C=");
Serial.print(data3);
Serial.print(" D=");
Serial.print(data4);
Serial.print(" E=");
Serial.print(data5);
Serial.print(" F=");
Serial.print(data6);
Serial.print("\n"); 
  //you should make this delay shorter then your transmit delay or else messages could be lost
  delay(50);
}
}



