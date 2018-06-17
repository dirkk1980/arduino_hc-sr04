# Arduino library for ultrasonic sensor HC-SR04
## Description
This library can be used for the ultrasonic sensor HC-SR04. All measured values are calculated in mm. The main features so far are:
- public functions
  - getting one single measurment
  - getting an average measurement result. count of measurements to calculate average can be set
  - ask for an obstacle in a givin range. optional caluclate this with an average value
- if sensor is getting timeout (no echo received), a value of 0 will be returned
## Examples
Examples can be found in folder Examples with detailed documentation of code