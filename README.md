# Aero_Maze_Ouija #


### Description ###
The Aero Maze Ouija is an apparatus consisting of a group of sensors coordinating a hexacopter whose main body is a marble maze.
The project is intended to be used as a teambuilding exercise. The game, as designed, is meant for six players.
Each player will be assigned a distance sensor which will be used to measure the length between the sensor and each player's hand.
This data is then sent to the drone and mapped to a PWM value to control the speed of each motor.
Each of the six motors is linked to one specific sensor, so each player will be in control of one propeller.
There will be a maze etched into the drone where there will be a marble or bb.
The goal of the game is to work as a team and navigate the marble through the maze by controlling the orientation of the drone.

![drone_overview](https://user-images.githubusercontent.com/29260218/28187684-2bd9d990-67e5-11e7-8d4f-728c548a2976.png)

- - - -

## Required Software and Libraries ##
* Arduino v1.8.1
* XCTU to setup Xbee's
* Autodesk Fusion 360 (Optional, but you can size the maze we designed)
* Arduino Libraries:
  * Teesnyduino
  * EasyTransfer Library
  
- - - -

## Required Hardware ##
* A body for your drone, preferably made out of fiberglass
* 6 Turnigy Aerodrive D3536/9 910 KV Motors
* 6 Mounts designed for the Turnigy motors
* 6 Propellers, we used 3 1045's and 3 1045R's
* 6 Metal U channels
* An assortment of screws
* 7 xBees
* 6 ESC's, we used 6 Hobby King 30A UBEC's
* 3 Leg stands to attach to the U channels
* Xbee explorer board to
* Breadboard to mount electronics
* At least 8 pairs of XT60 connectors and the corresponding wires

- - - -

## Tools Needed for Assembly ##

* CNC Router to sketch the maze
* Power tools needed to drill holes etc.
