/*
  Ultrasonic.h - Library for interacting with ultrasonic sensors like HC-SR04.
  Created by Dirk.
*/

#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"

//sonic speed in mm/microsecond
const float sonicSpeed = 0.34;

class Ultrasonic
{
  public:
    Ultrasonic (byte triggerPin, byte sensorPin, int sensorMaxDistance, int sensorMinDistance, int measurementInterval);
    int getDistance(boolean average = true, int countAverageMeasurements = 10);
    boolean getObstacle(int range, boolean average = true, int countAverageMeasurements = 10);
  private:
    byte _triggerPin;
    byte _sensorPin;
    int _sensorMaxDistance;
    int _sensorMinDistance;
    int _measurementInterval;
    unsigned long _timeout;
    unsigned long readSensor();
    unsigned long getAverage(int countAverageMeasurements);
};
#endif
