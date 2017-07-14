#include <Servo.h>

Servo esc;

void setup()
{
Serial.begin(9600); 
esc.attach(9);
delay(5000);
esc.write(179); // HI
delay(5000);
esc.write(1); // LO
delay(5000);
esc.write(90); // MID
delay(10000);

esc.write(120); // SPEED
Serial.println("Done");
}

void loop()
{
}
