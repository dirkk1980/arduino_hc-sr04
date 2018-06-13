/*
  HCSR04.h - Library for interacting with HCSR04 sensors like HC-SR04.
  Created by Dirk.
*/

#ifndef HCSR04_h
#define HCSR04_h

#include "Arduino.h"


//sensor specifications
#define SENSOR_MAX_DISTANCE         4000
#define SENSOR_MIN_DISTANCE         30
#define SENSOR_MEASUREMENT_INTERVAL 20

//sonic speed in mm/microsecond
const float sonicSpeed = 0.34;

class HCSR04
{
  public:
    HCSR04 (byte triggerPin, byte sensorPin);
    const int _sensorMaxDistance = 4000;
    const int _sensorMinDistance = 30;
    const int _measurementInterval = 20;
    int getDistance(boolean average = true, int countAverageMeasurements = 10);
    boolean getObstacle(int range, boolean average = true, int countAverageMeasurements = 10);
  private:
    byte _triggerPin;
    byte _sensorPin;
    unsigned long _timeout;
    unsigned long readSensor();
    unsigned long getAverage(int countAverageMeasurements);
};
#endif
