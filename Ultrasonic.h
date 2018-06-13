#ifndef Ultrasonic_h
#define Ultrasonic_h

#include "Arduino.h"

//sonic speed in centimeter/microsecond
#define SONIC_SPEED                0.034

class Ultrasonic
{
  public:
    Ultrasonic (byte triggerPin, byte sensorPin, int sensorMaxDistance, int sensorMinDistance);
    int getDistanceCM();
  private:
    byte _triggerPin;
    byte _sensorPin;
    int _sensorMaxDistance;
    int _sensorMinDistance;
    unsigned long _echoTime;
    void readSensor();
};
#endif
