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
    Ultrasonic (byte triggerPin, byte sensorPin, int sensorMaxDistance, int sensorMinDistance, int measurementInterval);
    int getDistanceCM(boolean average = true, int countAverageMeasurements = 10);
    boolean getObstacle(int range, boolean average = true, int countAverageMeasurements = 10);
  private:
    byte _triggerPin;
    byte _sensorPin;
    int _sensorMaxDistance;
    int _sensorMinDistance;
    int _measurementInterval;
    unsigned long readSensor();
    unsigned long getAverage(int countAverageMeasurements);
};
#endif
