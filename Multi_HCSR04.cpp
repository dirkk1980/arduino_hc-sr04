/*
  HCSR04.h - Library for interacting with HCSR04 sensor.
  Created by Dirk Köhler.
*/

#include "Arduino.h"
#include "Multi_HCSR04.h"
#include "HCSR04.h"

Multi_HCSR04::Multi_HCSR04(byte numSensors)
{
  _sensors = new HCSR04[numSensors]();
}