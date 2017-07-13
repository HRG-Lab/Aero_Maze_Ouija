# Aero_Maze_Ouija #


### Description ###
The Aero Maze Ouija is an apparatus consisting of a group of sensors coordinating a hexacopter whose main body is a marble maze.
The project is intended to be used as a teambuilding exercise. The game, as designed, is meant for six players.
Each player will be assigned a distance sensor which will be used to measure the length between the sensor and each player's hand.
This data is then sent to the drone and mapped to a PWM value to control the speed of each motor.
Each of the six motors are linked to one specific sensor, so each player will be in control of one propeller.
There will be a maze etched into the drone where there will be a marble or bb.
The goal of the game is to work as a team and navigate the marble through the maze by controlling the orientation of the drone.

![drone_overview](https://user-images.githubusercontent.com/29260218/28187684-2bd9d990-67e5-11e7-8d4f-728c548a2976.png)

- - - -

## Required Software and Libraries ##
* Arduino
* XCTU
* Autodesk Fusion 360 (Optional, but you can size the maze we designed)
* then the required libraries for Arduino

- - - -

## Required Hardware ##
* A body for your drone, preferably made out of fiberglass
* 6 Turnigy Aerodrive D3536/9 910 KV Motors
* 6 Mounts designed for the Turnigy motors
* 6 Propellers
* 6 Metal U channels
* An assortment of screws
* 7 xBees
* 6 Hobby King 30A UBEC's
* 3 Leg stands to attach to the U channels

- - - -

## Steps to Assemble ##

1. Drill holes in the wood where you will attach the channels
2. Cut a maze
3. Program the Xbees
4. Wire the sensors
5. Program the ESC's
6. Mount the motors
7. Test the motors/sensors with the test code
8. Enjoy
