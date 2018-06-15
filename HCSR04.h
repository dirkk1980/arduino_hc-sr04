/*
  HCSR04.h - Library for interacting with HCSR04 sensor.
  Created by Dirk Köhler.
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
    //max measureable distance of sensor in mm
    const int _sensorMaxDistance = 4000;
    //min measureable distance of sensor in mm
    const int _sensorMinDistance = 30;
    //time for one measurement in microsenconds
    const int _measurementInterval = 20;
    //get distance in mm, optional prameter can deactivate average measurement, count of measurements for avarage calculation can be set
    int getDistance(boolean average = true, int countAverageMeasurements = 10);
    //check if an obstacle is in given range, optional prameter can deactivate average measurement, count of measurements for avarage calculation can be set
    boolean getObstacle(int range, boolean average = true, int countAverageMeasurements = 10);
  private:
    byte _triggerPin;
    byte _sensorPin;
    unsigned long _timeout;
    unsigned long readSensor();
    unsigned long getAverage(int countAverageMeasurements);
};
#endif
