#### Areo-Smith Maze  ####

![image002](https://user-images.githubusercontent.com/29260264/30716439-a94e8304-9edf-11e7-8484-e1181e104f87.gif)

### Aerosmith Maze ###
* Diameter: 48 cm
* Thickness: 1.2 cm
 
 - - - -
 ![image003](https://user-images.githubusercontent.com/29260264/30824770-33f8e4cc-a1f6-11e7-97eb-0d08eaadc9d0.png)
 ![image004](https://user-images.githubusercontent.com/29260264/30824829-71620d7a-a1f6-11e7-8a2c-a71528adc6a3.gif)
 ![image020](https://user-images.githubusercontent.com/29260264/30824936-d1c16d50-a1f6-11e7-80b9-5415527e29c3.gif)
 ![image032](https://user-images.githubusercontent.com/29260264/30825217-c85f32be-a1f7-11e7-82a3-0dc082c4c400.gif)
![image035](https://user-images.githubusercontent.com/29260264/30825247-dd5dc702-a1f7-11e7-8d6a-d9c49f644494.gif)
![image036](https://user-images.githubusercontent.com/29260264/30825303-13699434-a1f8-11e7-8637-f4e0008514f1.gif)
![image037](https://user-images.githubusercontent.com/29260264/30825345-3d657d48-a1f8-11e7-92df-32eeb1e280d9.png)
![image042](https://user-images.githubusercontent.com/29260264/30825557-03e7090a-a1f9-11e7-96ae-c3a3d9a35553.gif)


### Overview ###
 &nbsp;&nbsp;For this project, the goal was to build a maze that a small metal bb pellet could navigate. This was done mainly through the use of teensy microcontrollers, ultrasonic sensors, ESC motors and xbee radio modules.
&nbsp;&nbsp;The maze outline, resembling a smith chart, was carved into a large, round piece of plexiglass with a CNC machine. Six ESC motors are attached to this piece of plexiglass, which tilt the maze in various directions, based on how fast each motor is spinning. This is how the bb navigates the maze, as each motor receives data from an ultrasonic sensor which tells it how fast or slow to spin. Each ultrasonic sensor will output a distance measurement based on how close or far an object is to it. The distance value that each sensor outputs is sent to a teensy microcontroller, which is programmed to send the data through an XBee module. The data is sent wirelessly to another XBee on the receiving end, which is connected to another teensy. This teensy is attached to the plexiglass maze, and is programmed to control all of the 6 motors, based on the different values it receives from each of the 6 sensors.
&nbsp;&nbsp;The maze is designed to be controlled by 6 different people at one time, with each person controlling one motor by moving their hands in front of an ultrasonic sensor. Based on how the teensys were programmed, the closer your hand is to the ultrasonic sensor, the faster the motor will spin. Therefore, to tilt the maze up in one direction, one person will have to move their hand closer to the ultrasonic sensor that corresponds to that specific motor. The maze is attached to a ball and socket joint which is tethered to a tripod, which allows it the freedom to rotate in any direction, without the maze flying away due to the lift of the motors. This project was designed to encourage people to work together to complete a task, and the maze is best navigated when the speed of one motor is changed at a time.
&nbsp;&nbsp;This document will outline the materials needed and the steps that should be  taken in order to build the Aerosmith maze, and a list of references that was used will be included at the end.

### Required Materials ###
* 1 Round piece of wood 
* 6 Turnigy Aerodrives motors (D3536/9 910KV) (https://hobbyking.com/en_us/turnigy-d3536-9-910kv-brushless-outrunner-motor.html)
* 6 Electronic Speed controllers (Hobby King 30A UBEC) (https://hobbyking.com/en_us/hobby-king-30a-esc-3a-ubec.html)
* 6 Propellors: 3 1045R, 3 1045 (https://www.newegg.com/Product/Product.aspx?Item=9SIA2RP0XW3805)
* 6 Metal Channels (http://www.johnsonrollforming.com/display.php/display/A1/category/2)
* 3 3D printed legs
* 6 3D printed motor mounts
* 6 Metal cross brackets for motor mounts (http://www.crlaurence.com/crlapps/showline/offerpage.aspx?ProductID=11909&GroupID=14911&History=39325:22043:7146:14894:14906:14894&ModelID=14911&pom=0)
* 1 power supply (BK precision 1900) (http://www.bkprecision.com/products/power-supplies/1900-1-16v-60a-switching-dc-power-supply.html)
* 7 breadboards 16.5 cm x 5.5 cm (https://www.itead.cc/breadboard-16-5-x-5-5cm.html)
* 7 XBee PRO S1 With Antennas (https://www.sparkfun.com/products/8742)
* 7 Teensy LC or Teensy 3.0 (https://www.pjrc.com/teensy/teensyLC.html)
* 7 Teensy to XBee Adaptor kits (https://www.sparkfun.com/products/13311)
* 6 parallax 28015 ping ultrasonic range finder or XL-MaxSonar –EZ/AE Ultrasonic range finder (https://www.parallax.com/product/28015)
* XBee Explorer Dongle (https://www.sparkfun.com/products/11697)
* Assorted nuts and screws
 
 
### Required Software ###
 
* Arduino 1.8.3 (https://www.arduino.cc/en/main/software)
* Teensyduino (https://www.pjrc.com/teensy/teensyduino.html)
* EasyTransfer Library (https://github.com/madsci1016/Arduino-EasyTransfer)
* XCTU (Source 8)
* AutoCAD Fusion 360 (https://www.autodesk.com/products/fusion-360/overview)
* Anaconda
* Pycharm
* PySerial

- - - -
 
## Setting up Software ##
 
* You will need to download and install Arduino 1.8.3 onto your computer if you do not already have Arduino installed. Leave all settings as default. Open up Arduino and try uploading a blank code to your device, or maybe a simple blink program. Make sure the right board is selected by going to Tools->Board:-> and select the device you are trying to upload the code to, such as Arduino Genuino/Uno, Teensy LC, or Teensy 3.0. 
* For Teensy 3.0 and Teensy LC it is necessary to have the Teensyduino downloaded. Do not change any of the settings or file locations when downloading Teensyduino, everything will be automatically setup for you.  When using Teensy 3.0 it will be necessary to change the frequency of the device by going to `Tools->CPU Speed:->` and changing it from 96 MHz (overclocked) to 48 MHz to avoid damaging the device. 
* The library EasyTransfer will need to be downloaded for this project and installed in the correct file. To do this find your Arduino folder stored in your hard drive at a location such as `c/Program Files (x86)/Arduino/library` and copy the unzipped EasyTransfer library into the library folder. 
* To configure the XBee’s you will need to have XCTU downloaded and installed on your computer. Download the latest version of XCTU and install it on your computer without changing any of the default settings. 

- - - -

### Motor Testing ###
* To test motors, wire pin 9 of the Arduino to the signal wire of the ESC and the ground wire of the Arduino to the ground wire of the ESC. Also, attach the servomotor and the power supply to the ESC. 

    <img src="https://user-images.githubusercontent.com/29260218/28725444-0d3c0ba8-7383-11e7-82be-f450642e92c8.jpg" width="500">
    
    *Pictured Above: Wiring of Servo Motor for testing*

* Upload the code to the Arduino and open the serial monitor. Type in a value and your motor’s speed will gradually rise or fall to match your entered value.

- - - -

## Programmming the ESC’s ##

* The arduino file underneath the filepath: `Arduino Code/Program ESC/ESCProgrammer/ESCProgrammer.ino` is designed to program the electronic speed controllers so that when the ESC’s are controlling the speed of the motors, the motors will turn on at roughly the same value and spin at similar rates.

1. Plug in an arduino to your computer and attach the ground port on the arduino to the ground pin (black wire) on the ESC PWM wires and port 9 on the arduino to the signal pin (white wire) on the ESC PWM wires. Also, attach power wires to the ESC.

    <img src="https://user-images.githubusercontent.com/29260218/28723941-038f6730-737e-11e7-86fa-0d7f2b5d8a93.jpg" width="500">
    
    *Pictured Above: how to configure wires to ESC to program*

2. Before uploading the code, disconnect and reconnect the power supply to the ESC, this will allow the ESC to be programmed. Upload the code located in the aforementioned file path and upload this onto the board. Open the serial monitor and wait for the text “Done” to appear.

3. Repeat these steps on all the ESC’s until all are programmed.

- - - -

## Configure XBee setup ##

* Once XCTU installed connect the XBee using the XBee Explorer Dongle and open XCTU. Click on “Discover Radio Modules connected to your machine” and select the USB serial ports that show up. Click Next and then Click finish. If the device does not show up the first time you may need to select more Baud rates before clicking finish. Click “Add selected devices”, and then click on the selected device to configure it and access the console. The configuration settings used are pictured below. 

    <img src="https://user-images.githubusercontent.com/29260218/28724001-3ffcfe8a-737e-11e7-8a7c-7c182efc1cba.png" width="500">
    
    *Pictured Above: The Settings window for XBee module displaying the settings we used*

* The only thing that was changed from the default was changing the Network ID from 7FFF to 8FFF. To communicate between two XBees select the console tab which is located right next to the settings tab and click the “Open/Close” button. This allows for you to see the messages sent by other networks on you console screen and send messages from the console screen to other XBees in the same network.

    <img src="https://user-images.githubusercontent.com/29260218/28724037-61ca7312-737e-11e7-96cd-42537032a212.png" width="500">
    
    *Pictured Above: Console window showing two XBees communicating with each other. The red text is from the other XBee, while the blue text is from the XBee that is connected to your device*

- - - -

## Configure Distance Transmission Setup ##

### Distance Sensor Setup ###

* Using a Teensy 3.0 or Teensy LC connect the distance sensor that is being used according to the following setup: Connect the GND pins to each other, the 5V pin to Vin on Teensy 3.0 or 5V on Teensy LC or Arduino Uno. Connect the signal pin (for the parallax 28015 ping ultrasonic range finder it is labeled SIG and for the XL-MaxSonar –EZ/AE Ultrasonic range finder it is pin 3) to an analog pin (In the code used in the project it is pin 14 for Teensy 3.0 and Teensy LC).

* For the parallax 28015 ping ultrasonic range finder we found code for measuring the distance at this link https://www.arduino.cc/en/Tutorial/Ping. This code relies on sending a pulse signal through the sensor and measuring the delay of the returning signal, and converting the time using the speed of sound to convert it into inches and centimeters. The code that was used in the project used the function to send out the pulse signal and convert it to centimeters. Pictured below is the sensor used.


    <img src="https://user-images.githubusercontent.com/29260218/28724234-f4405162-737e-11e7-80af-19e090d9580d.jpg" width="250">

* The code used in the project can be found at the filepath `Aero_Maze_Ouija/Arduino Code/Drone Code/Distance_Transmission_28015/Distance_Transmission_28015.ino`. This code provided accurate readings from 5cm to 80cm. If you are using this code for a board other than Teensy 3.0 or Teensy LC you may need to comment out lines involving Serial3 as this will cause an error when compiling. The distances will be displayed on the serial monitor.

* For the XL-MaxSonar –EZ/AE Ultrasonic range finder we created our own distance conversion code by taking in the signal using analogRead() to read in data from the pin connected to the sensor and printing the value to the serial monitor. We recorded the values produced by analogRead() along with the distances that we placed an object at from 95 cm to 20 cm every 5 cm (a limitation of this sensor is that it can not measure anything below 20 cm) plotted it to determine an equation that fit it, coming up with distance = (.6869*val)+2 where val is the integer value that is read in from analogRead().Below is a picture of this sensor.


    <img src="https://user-images.githubusercontent.com/29260218/28724352-4d51dafa-737f-11e7-97c6-279a8c456757.jpg" width="250">

* The code can be found at `Aero_Maze_Ouija/Arduino Code/Drone Code/Distance_Transmission_MAXSONAR/Distance_Transmission_MAXSONAR.ino` This code will provide fairly accurate readings (+- 3 cm)  from 20 cm to 95 cm. If this code does not seem as accurate as you would like you will need to go through the mapping process described above.

- - - -

## XBee Adaptor Connection ##

* This part requires an XBee adaptor board to connect the XBee to the Teensy. The one used in this project can be found here https://www.pjrc.com/store/xbee_adaptor.html. (Note: this page recommends that you do not use these boards for any new projects, but we used them in this project as we already them). Follow the steps outlined in this page to configure these for Teensy 2.0. It is important to follow the instructions outlined in the page for using it with Teensy LC or 3.0 as the boards were designed for the regulator chip to handle the 5V from the Teensy 2.0 or 2.0++, which means that for using with Teensy LC or 3.0 requires the 15k resistor to not be connected. Below is an image an adaptor showing the configuration used in this project.

    <img src="https://user-images.githubusercontent.com/29260218/28724404-7e5c01c0-737f-11e7-9240-b512439a4a5d.jpg" width="250">

* In the code you will also need to include the lines XBee xbee = XBee(); and Serial3.begin(9600). A test code we used to verify that we could communicate through the Teensys and XBee setup can be found at the file-path:
`Aero_Maze_Ouija/Arduino Code/Test Code/communication_Test/communication Test.ino`
	
* This code allows you to send messages to and from the serial monitor.

* To connect the adaptor board-XBee setup to the Teensy 3.0 or Teensy LC follow this diagram below:
![image020](https://user-images.githubusercontent.com/29260264/30824936-d1c16d50-a1f6-11e7-80b9-5415527e29c3.gif)
- - - -

## Configure Distance Receiving/Motor Control Setup ##

### XBee Adaptor Connection ###

* See XBee Adaptor Connection under Configure Distance Transmission Setup

### Motor Connection Guide ###

* Each esc has a 3 input connection, the black wire will be connected to the ground of the Teensy and the white wire will be connected to the signal. Leave the middle red wire empty. Connect the signal wire to a pin on the Teensy (in our code we used pins 2-6 and 9).

    <img width="625" alt="screen shot 2017-07-28 at 10 30 46 am" src="https://user-images.githubusercontent.com/29260218/28724523-e831299a-737f-11e7-9cc6-d606a96bf71a.png">
    
    *Pictured Left: the three input connection: This is used in programming the esc and will be connected to the Teensy. Middle: This shows the wires from the Teensy connected to the three input connection (note that the green wires in this image represent the ground wire). Left: The esc with the input side (top) and output side to be connected to the motors (bottom)*

## Insert image of the signal wires ##

* The code for receiving the packets of data and sending out a signal to the motors can be found under the file-path:
`Aero_Maze_Ouija/Arduino Code/Drone Code/_6_Motors_Recieving/_6_Motors_Recieving.ino`

* The red and black power cables on the input side of the esc  will be connect to power and ground of the power supply respectively. On the output side of the esc the connection cables should alternate the connection between the black and colored wires, with red still going to red. So the setup would be red-red, blue-yellow, black-black; and for the next esc-motor setup it should be red-red, black-yellow, blue-black. This can be seen in the picture below. 


    <img width="500" alt="screen shot 2017-07-28 at 11 04 02 am" src="https://user-images.githubusercontent.com/29260218/28725892-91465600-7384-11e7-9dc5-7e801cf35882.png">
    
    *Pictured Left: Showing the connection red-red, blue-black, black-yellow. Pictured Right: Showing the connection red-red, blue-yellow, black-black*
               

* It incorporates the easy transfer library to receive the distances and an identifying character from each setup, and then case structures to select between the different characters and control individual motors.


## Designing The Maze ##

* Using the software Autodesk Fusion 360 we have designed a marble maze that is based upon a Smith chart. Using the parameters menu one can easily reconfigure the size and dimensions of the maze to fit the almost any size board. One can easily find the software underneath Autodesk’s official website and receive a one month free trial to quickly generate an STL underneath any size they wish. The STL we have included in our files is a maze designed for a 14 inch diameter round piece of wood.

## Modifying the Maze ##

* In Autodesk Fusion 360, open the parameters menu and the main parameters the user will want to modify will be:
	* body_diameter - Set the diameter of your wood
	* trough_width - Set the width of the guiding structures of the maze
	* trough_depth - Set the depth of the guiding structures
	* end_hole_depth - Set the depth of the center hole in the maze
	* distance_guide - Is approximately the distance between the center of the neighboring guiding structure and the guiding structure that the former cuts off. One should tinker with this parameter to get the correct dimensions for their maze.


## Producing 3D Printed Housing ##

* Using Autodesk Fusion 360 
	* The housing for the sensors consisted of a 3D printed box and lid seen below
	![image037](https://user-images.githubusercontent.com/29260264/30825345-3d657d48-a1f8-11e7-92df-32eeb1e280d9.png)
        ![image042](https://user-images.githubusercontent.com/29260264/30825557-03e7090a-a1f9-11e7-96ae-c3a3d9a35553.gif)
	* Brackets were made for the maze to be mounted on
	![image032](https://user-images.githubusercontent.com/29260264/30825217-c85f32be-a1f7-11e7-82a3-0dc082c4c400.gif)
	![image035](https://user-images.githubusercontent.com/29260264/30825247-dd5dc702-a1f7-11e7-8d6a-d9c49f644494.gif)
	![image036](https://user-images.githubusercontent.com/29260264/30825303-13699434-a1f8-11e7-8637-f4e0008514f1.gif)
	* Casing for the recieving and motor control setup was made
