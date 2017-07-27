## Motor Testing ##
 To test motors, wire pin 9 of the Arduino to the signal wire of the ESC and the ground wire of the Arduino to the ground wire of the ESC. Also, attach the servomotor and the power supply to the ESC. 


Pictured Above: Wiring of Servo Motor for testing

Upload the code to the Arduino and open the serial monitor. Type in a value and your motor’s speed will gradually rise or fall to match your entered value.




## Programmming the ESC’s ##

 	The arduino file underneath the filepath: Arduino Code->Program ESC->ESCProgrammer->ESCProgrammer.ino, is designed to program the electronic speed controllers so that when the ESC’s are controlling the speed of the motors, the motors will turn on at roughly the same value and spin at similar rates.

Plug in an arduino to your computer and attach the ground port on the arduino to the ground pin (black wire) on the ESC PWM wires and port 9 on the arduino to the signal pin (white wire) on the ESC PWM wires. Also, attach power wires to the ESC.

Pictured Above: how to configure wires to ESC to program

Before uploading the code, disconnect and reconnect the power supply to the ESC, this will allow the ESC to be programmed. Upload the code located in the aforementioned file path and upload this onto the board. Open the serial monitor and wait for the text “Done” to appear.
Repeat these steps on all the ESC’s until all are programmed.

Configure XBee setup

Once XCTU installed connect the XBee using the XBee Explorer Dongle and open XCTU. Click on “Discover Radio Modules connected to your machine” and select the USB serial ports that show up. Click Next and then Click finish. If the device does not show up the first time you may need to select more Baud rates before clicking finish. Click “Add selected devices”, and then click on the selected device to configure it and access the console. The configuration settings used are pictured below. 

Pictured Above: The Settings window for XBee module displaying the settings we used

The only thing that was changed from the default was changing the Network ID from 7FFF to 8FFF. To communicate between two XBees select the console tab which is located right next to the settings tab and click the “Open/Close” button. This allows for you to see the messages sent by other networks on you console screen and send messages from the console screen to other XBees in the same network.

Pictured Above: Console window showing two XBees communicating with each other. The red text is from the other XBee, while the blue text is from the XBee that is connected to your device.

Configure Distance Transmission Setup

Distance Sensor Setup

Using a Teensy 3.0 or Teensy LC connect the distance sensor that is being used according to the following setup: Connect the GND pins to each other, the 5V pin to Vin on Teensy 3.0 or 5V on Teensy LC or Arduino Uno. Connect the signal pin (for the parallax 28015 ping ultrasonic range finder it is labeled SIG and for the XL-MaxSonar –EZ/AE Ultrasonic range finder it is pin 3) to an analog pin (In the code used in the project it is pin 14 for Teensy 3.0 and Teensy LC).

For the parallax 28015 ping ultrasonic range finder we found code for measuring the distance at this link https://www.arduino.cc/en/Tutorial/Ping . This code relies on sending a pulse signal through the sensor and measuring the delay of the returning signal, and converting the time using the speed of sound to convert it into inches and centimeters. The code that was used in the project used the function to send out the pulse signal and convert it to centimeters. Pictured below is the sensor used.


The code used in the project can be found at the filepath Aero_Maze_Ouija->Arduino Code->Drone Code->Distance_Transmission_28015->Distance_Transmission_28015.ino. This code provided accurate readings from 5cm to 80cm. If you are using this code for a board other than Teensy 3.0 or Teensy LC you may need to comment out lines involving Serial3 as this will cause an error when compiling. The distances will be displayed on the serial monitor.

For the XL-MaxSonar –EZ/AE Ultrasonic range finder we created our own distance conversion code by taking in the signal using analogRead() to read in data from the pin connected to the sensor and printing the value to the serial monitor. We recorded the values produced by analogRead() along with the distances that we placed an object at from 95 cm to 20 cm every 5 cm (a limitation of this sensor is that it can not measure anything below 20 cm) plotted it to determine an equation that fit it, coming up with distance = (.6869*val)+2 where val is the integer value that is read in from analogRead().  Below is a picture of this sensor.


The code can be found at Aero_Maze_Ouija->Arduino Code->Drone Code->Distance_Transmission_MAXSONAR->Distance_Transmission_MAXSONAR.ino. This code will provide fairly accurate readings (+- 3 cm)  from 20 cm to 95 cm. If this code does not seem as accurate as you would like you will need to go through the mapping process described above. 

XBee Adaptor Connection

	This part requires an XBee adaptor board to connect the XBee to the Teensy. The one used in this project can be found here https://www.pjrc.com/store/xbee_adaptor.html. (Note: this page recommends that you do not use these boards for any new projects, but we used them in this project as we already them). Follow the steps outlined in this page to configure these for Teensy 2.0. It is important to follow the instructions outlined in the page for using it with Teensy LC or 3.0 as the boards were designed for the regulator chip to handle the 5V from the Teensy 2.0 or 2.0++, which means that for using with Teensy LC or 3.0 requires the 15k resistor to not be connected. Below is an image an adaptor showing the configuration used in this project.



 In the code you will also need to include the lines XBee xbee = XBee(); and Serial3.begin(9600). A test code we used to verify that we could communicate through the Teensys and XBee setup can be found at the file-path Aero_Maze_Ouija->Arduino Code->Test Code->communication_Test->communication Test.ino. This code allows you to send messages to and from the serial monitor.

	To connect the adaptor board-XBee setup to the Teensy 3.0 or Teensy LC follow this diagram below:

	
 
Configure Distance Receiving/Motor Control Setup

XBee Adaptor Connection

See XBee Adaptor Connection under Configure Distance Transmission Setup

Motor Connection Guide

	Each esc has a 3 input connection, the black wire will be connected to the ground of the Teensy and the white wire will be connected to the signal. Leave the middle red wire empty. Connect the signal wire to a pin on the Teensy (in our code we used pins 2-6 and 9). 




Pictured Left: the three input connection: This is used in programming the esc and will be connected to the Teensy. Middle: This shows the wires from the Teensy connected to the three input connection (note that the green wires in this image represent the ground wire). Left: The esc with the input side (top) and output side to be connected to the motors (bottom) 
                                   Insert image of the signal wires

The code for receiving the packets of data and sending out a signal to the motors can be found under the file-path Aero_Maze_Ouija->Arduino Code->Drone Code-> _6_Motors_Recieving->_6_Motors_Recieving.ino.
The red and black power cables on the input side of the esc  will be connect to power and ground of the power supply respectively. On the output side of the esc the connection cables should alternate the connection between the black and colored wires, with red still going to red.
So the setup would be red-red,blue-yellow,black-black; and for the next esc-motor setup it should be red-red,black-yellow,blue,black. This can be seen in the picture below. 




Pictured Left: Showing the connection red-red,blue-black,black-yellow. Pictured Right: Showing the connection red-red,blue-yellow,black-black.
               


	It incorporates the easy transfer library to receive the distances and an identifying character from each setup, and then case structures to select between the different characters and control individual motors.
