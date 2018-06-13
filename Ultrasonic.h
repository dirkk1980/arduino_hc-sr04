/*
  Ultrasonic.h - Library for interacting with ultrasonic sensors like HC-SR04.
  Created by Dirk.
*/

#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"

//sonic speed in centimeter/microsecond
#define SONIC_SPEED                0.034

class Ultrasonic
{
  public:
    Ultrasonic (byte triggerPin, byte sensorPin, int sensorMaxDistance, int sensorMinDistance, byte measurementInterval);
    int getDistanceCM();
    boolean getObstacle(int range);
  private:
    byte _triggerPin;
    byte _sensorPin;
    int _sensorMaxDistance;
    int _sensorMinDistance;
    byte _measurementInterval;
    unsigned long _echoTime;
    void readSensor();
};
#endif
