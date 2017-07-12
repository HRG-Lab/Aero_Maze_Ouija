#include <EasyTransfer.h>

const int pingPin = 14;
float val = 500; 
char serialReadVal;
int dataCMVal;
// variable to store the values from sensor(initially zero)

EasyTransfer ET; //creates object

struct SEND_DATA {   //puts all the variables inside a struct to send a packet of data
  char id='a';
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

    while (Serial.available()) {
 
      serialReadVal = Serial.read();

      if (serialReadVal == 'q') {
        
        while (1) { // ************************ Start Parse
        if (Serial.available()) {
          while(Serial.available()) {
        dataCMVal = Serial.parseFloat();
          }
         break; 
        }
      } // ********************* Finish Parse
data.id = 'a';
        data.cm = dataCMVal;
        ET.sendData();
        delay(1);
        
        data.id = 'b';
        data.cm = dataCMVal;
        ET.sendData();
        delay(1);

        data.id = 'c';
        data.cm = dataCMVal;
        ET.sendData();
        delay(1);

        data.id = 'd';
        data.cm = dataCMVal;
        ET.sendData();
        delay(1);

        data.id = 'e';
        data.cm = dataCMVal;
        ET.sendData();
        delay(1);

        data.id = 'f';
        data.cm = dataCMVal;
        ET.sendData();
        delay(1);
      
      }

     else {
      data.id = serialReadVal;
        while (1) { // ************************ Start Parse
        if (Serial.available()) {
          while(Serial.available()) {
        dataCMVal = Serial.parseFloat();
        data.cm = dataCMVal;
          }
         break; 
        }
      } // ********************* Finish Parse
     }
     
  }
  Serial.print(data.id);
  Serial.print(", ");
  Serial.println(data.cm);            // prints the value of the sensor to the serial monitor

  //send the data
  ET.sendData();

  //Serial3.println(data.cm);
  delay(250);                    // wait for this much time before printing next value
}
