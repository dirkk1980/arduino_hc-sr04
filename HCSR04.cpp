/*
  HCSR04.h - Library for interacting with HCSR04 sensor.
  Created by Dirk Köhler.
*/

#include "Arduino.h"
#include "HCSR04.h"

HCSR04::HCSR04(byte triggerPin, byte sensorPin)
{
  _triggerPin = triggerPin;
  _sensorPin = sensorPin;
  pinMode(_triggerPin, OUTPUT);              
  pinMode(_sensorPin, INPUT);     
 _timeout = _sensorMaxDistance / sonicSpeed;
}

//reading echo time from sensor
unsigned long HCSR04::readEchoTime()
{
  //disable trigger for x miliseconds to get a clear signal
  digitalWrite(_triggerPin, LOW);
  delayMicroseconds(3);
  
  //sending and receiving new signal, using interrupts in fact of time critival function
  noInterrupts();
  digitalWrite(_triggerPin, HIGH); 
  delayMicroseconds(_measurementInterval);
  digitalWrite(_triggerPin, LOW);
  _echoTime = pulseIn(_sensorPin, HIGH, _timeout); 
  interrupts();
  
  //check if returns timeout
  if (_echoTime > 0)
  {
    _echoTime = (_echoTime / 2); 
  }
  else
  {
    _echoTime = 0;
  }
  return _echoTime;
}

//reading x signals and returning average value
unsigned int HCSR04::getAverage(int countAverageMeasurements)
{

  unsigned long measurementValues[countAverageMeasurements];
  for (int i = 0; i <= countAverageMeasurements; i++)
  {
    measurementValues[i] = readEchoTime();
    //delay to prevent overlapping sensor readings
    delayMicroseconds(_timeout * 2);
  }
  unsigned long sumMeasurementvalues = 0;
  for (int i = 0; i <= countAverageMeasurements; i++)
  {
    sumMeasurementvalues += measurementValues[i];
  }
  return sumMeasurementvalues / countAverageMeasurements;
}

//get single distance measurement value
unsigned int HCSR04::getDistance(boolean average = true, int countAverageMeasurements = 10)
{
  if (average == true)
  {
    return getAverage(countAverageMeasurements) * sonicSpeed;
  }
  else
  {
    readEchoTime() * sonicSpeed;
  }
}

//check if there is an obstacle in giving range
boolean HCSR04::getObstacle(int range, boolean average = true, int countAverageMeasurements = 10)
{
  int distance = getDistance(average, countAverageMeasurements);
  //check if in distance and if measurement is not zero by timeout
  if (distance <= range && distance > 0)
  {
    return true;
  }
  else 
  {
    return false;
  }
}