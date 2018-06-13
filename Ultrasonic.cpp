#include "Arduino.h"
#include "Ultrasonic.h"

Ultrasonic::Ultrasonic(byte triggerPin, byte sensorPin, int sensorMaxDistance, int sensorMinDistance)
{
  pinMode(triggerPin, OUTPUT);              
  pinMode(sensorPin, INPUT);     
 _triggerPin = triggerPin;
 _sensorPin = sensorPin;
 _sensorMaxDistance = sensorMaxDistance;
 _sensorMinDistance = sensorMinDistance;
}

void Ultrasonic::readSensor()
{
  //disable trigger for x miliseconds to get a clear signal
  digitalWrite(_triggerPin, LOW);
  delayMicroseconds(3);
  
  //sending and receiving new measurement
  noInterrupts();
  digitalWrite(_triggerPin, HIGH); 
  delayMicroseconds(20);
  digitalWrite(_triggerPin, LOW);
  //reading echo with a timeout calculated by the max distance of the sensor
  _echoTime = pulseIn(_sensorPin, HIGH, _sensorMaxDistance / SONIC_SPEED); 
  interrupts();
  _echoTime = (_echoTime / 2); 
}

int Ultrasonic::getDistanceCM()
{
  readSensor();
  //return distance in cm
  return int(_echoTime * SONIC_SPEED);
}

