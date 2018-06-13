#include <Arduino.h>
#include <Ultrasonic.h>

//global debug flag
#define DEBUG

//pin configuration
#define FRONT_SENSOR_TRIGGER_PIN    13
#define FRONT_SENSOR_ECHO_PIN       12
//sensor specifications
#define SENSOR_MAX_DISTANCE         4000
#define SENSOR_MIN_DISTANCE         30
#define SENSOR_MEASUREMENT_INTERVAL 20

Ultrasonic frontSensor (
FRONT_SENSOR_TRIGGER_PIN,
FRONT_SENSOR_ECHO_PIN,
SENSOR_MAX_DISTANCE,
SENSOR_MIN_DISTANCE,
SENSOR_MEASUREMENT_INTERVAL);        

void setup() {                          
  #ifdef DEBUG
  Serial.begin(9600);  
  Serial.println("Setup finished");
  #endif
}

void loop() {
  #ifdef DEBUG
  Serial.println("\nSingle measured distance:");
  Serial.print(frontSensor.getDistance(false));
  Serial.print(" cm");

  Serial.println("\nAverage of 10 measurements:");
  Serial.print(frontSensor.getDistance());
  Serial.print(" cm");

  Serial.println("\nObstacle in given range of 50 cm found with avergare option on:");
  Serial.print(frontSensor.getObstacle(50));

  Serial.println("\nObstacle in given range of 50 cm found with avergare option off:");
  Serial.print(frontSensor.getObstacle(50,false));
  #endif
  //wait one second
  delay(1000);
}
