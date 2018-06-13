#include "Arduino.h"
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(byte triggerPin, byte sensorPin, int sensorMaxDistance, int sensorMinDistance, byte measurementInterval)
{
  pinMode(triggerPin, OUTPUT);              
  pinMode(sensorPin, INPUT);     
 _triggerPin = triggerPin;
 _sensorPin = sensorPin;
 _sensorMaxDistance = sensorMaxDistance;
 _sensorMinDistance = sensorMinDistance;
 _measurementInterval = measurementInterval;
}

void Ultrasonic::readSensor()
{
  //disable trigger for x miliseconds to get a clear signal
  digitalWrite(_triggerPin, LOW);
  delay(1);
  
  //sending and receiving new measurement
  noInterrupts();
  digitalWrite(_triggerPin, HIGH); 
  delay(_measurementInterval);
  digitalWrite(_triggerPin, LOW);
  
  //reading echo with a timeout calculated by the max distance of the sensor
  _echoTime = pulseIn(_sensorPin, HIGH, _sensorMaxDistance / SONIC_SPEED); 
  interrupts();
  
  //check if timeout
  if (_echoTime != 0)
  {
    _echoTime = (_echoTime / 2); 
  }
}

int Ultrasonic::getDistanceCM()
{
  readSensor();
  
  //return distance in cm
  return int(_echoTime * SONIC_SPEED);
}

