/*
  Ultrasonic.h - Library for interacting with ultrasonic sensors like HC-SR04.
  Created by Dirk.
*/

#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"

//sonic speed in centimeter/microsecond
const float sonicSpeed = 0.034;

class Ultrasonic
{
  public:
    Ultrasonic (byte triggerPin, byte sensorPin, unsigned int sensorMaxDistance, unsigned int sensorMinDistance, unsigned int measurementInterval);
    unsigned int getDistanceCM();
    boolean getObstacle(int range);
  private:
    byte _triggerPin;
    byte _sensorPin;
    unsigned int _sensorMaxDistance;
    unsigned int _sensorMinDistance;
    unsigned int _measurementInterval;
    unsigned long _echoTime;
    void readSensor();
};
#endif
