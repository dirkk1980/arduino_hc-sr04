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
}

unsigned long Ultrasonic::readSensor()
{
  static unsigned long _echoTime;
  //disable trigger for x miliseconds to get a clear signal
  digitalWrite(_triggerPin, LOW);
  delay(1);
  
  //sending and receiving new measurement
  noInterrupts();
  digitalWrite(_triggerPin, HIGH); 
  delay(_measurementInterval);
  digitalWrite(_triggerPin, LOW);
  
  //reading echo with a timeout calculated by the max distance of the sensor
  _echoTime = pulseIn(_sensorPin, HIGH, _sensorMaxDistance / sonicSpeed); 
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
    }
  static unsigned long sumMeasurementvalues = 0;
    for (int i = 0; i <= countAverageMeasurements; i++)
    {
      sumMeasurementvalues += measurementValues[i];
    }
    return sumMeasurementvalues / countAverageMeasurements;
}

int Ultrasonic::getDistanceCM(boolean average = true, int countAverageMeasurements = 10)
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
  if (getDistanceCM(average,countAverageMeasurements) <= range)
  {
    return true;
  }
  else 
  {
    return false;
  }
}

