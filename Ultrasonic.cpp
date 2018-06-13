#include "Arduino.h"
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(byte triggerPin, byte sensorPin, int sensorMaxDistance, int sensorMinDistance, int measurementInterval)
{
  pinMode(triggerPin, OUTPUT);              
  pinMode(sensorPin, INPUT);     
 _triggerPin = triggerPin;
 _sensorPin = sensorPin;
 _sensorMaxDistance = sensorMaxDistance;
 _sensorMinDistance = sensorMinDistance;
 _measurementInterval = measurementInterval;
 _timeout = _sensorMaxDistance / sonicSpeed;
}

unsigned long Ultrasonic::readSensor()
{
  static unsigned long _echoTime;
  //disable trigger for x miliseconds to get a clear signal
  digitalWrite(_triggerPin, LOW);
  delayMicroseconds(3);
  
  //sending and receiving new measurement
  noInterrupts();
  digitalWrite(_triggerPin, HIGH); 
  delayMicroseconds(_measurementInterval);
  digitalWrite(_triggerPin, LOW);
  _echoTime = pulseIn(_sensorPin, HIGH, _timeout); 
  interrupts();
  
  //check if timeout
  if (_echoTime != 0)
  {
    _echoTime = (_echoTime / 2); 
  }
  return _echoTime;
}

unsigned long Ultrasonic::getAverage(int countAverageMeasurements)
{
  unsigned long measurementValues[countAverageMeasurements];
    for (int i = 0; i <= countAverageMeasurements; i++)
    {
      measurementValues[i] = readSensor();
      delay(_timeout * 2);
    }
  static unsigned long sumMeasurementvalues = 0;
    for (int i = 0; i <= countAverageMeasurements; i++)
    {
      sumMeasurementvalues += measurementValues[i];
    }
    return sumMeasurementvalues / countAverageMeasurements;
}

int Ultrasonic::getDistance(boolean average = true, int countAverageMeasurements = 10)
{
  if (average == true)
  {
    return int(getAverage(countAverageMeasurements) * sonicSpeed);
  }
  else
  {
    return int(readSensor() * sonicSpeed);
  }
}

boolean Ultrasonic::getObstacle(int range, boolean average = true, int countAverageMeasurements = 10)
{
  if (getDistance(average,countAverageMeasurements) <= range)
  {
    return true;
  }
  else 
  {
    return false;
  }
}

