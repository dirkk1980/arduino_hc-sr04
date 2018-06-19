#include <Arduino.h>
#include <HCSR04.h>

//pin configuration
#define FRONT_SENSOR_TRIGGER_PIN    10
#define FRONT_SENSOR_ECHO_PIN       11
#define REAR_SENSOR_TRIGGER_PIN    12
#define REAR_SENSOR_ECHO_PIN       13

HCSR04 frontSensor (
  FRONT_SENSOR_TRIGGER_PIN,
  FRONT_SENSOR_ECHO_PIN
);        

HCSR04 rearSensor (
  REAR_SENSOR_TRIGGER_PIN,
  REAR_SENSOR_ECHO_PIN
);     

Multi_HCSR04 ultrasonicSensorController (2);

void setup() {                          
  Serial.begin(9600);  
  Serial.println("Setup finished");
}

void loop() {

}