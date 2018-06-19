/*
  HCSR04.h - Library for interacting with HCSR04 sensor.
  Created by Dirk Köhler.
*/

#ifndef Multi_HCSR04_h
#define Multi_HCSR04_h

#include "Arduino.h"
#include "HCSR04.h"

class Multi_HCSR04
{
  public:
    Multi_HCSR04 (byte numSensors);
  private:
    HCSR04* _sensors [];
};
#endif