#include <Arduino.h>
#include <HCSR04.h>

//pin configuration
#define FRONT_SENSOR_TRIGGER_PIN    12
#define FRONT_SENSOR_ECHO_PIN       13

HCSR04 sensor (
  FRONT_SENSOR_TRIGGER_PIN,
  FRONT_SENSOR_ECHO_PIN
);        

void setup() {                          
  Serial.begin(9600);  
  Serial.println("Setup finished");
}

void loop() {
  Serial.println("\nSingle measured distance:");
  Serial.print(sensor.getDistance(false));
  Serial.print(" mm");

  Serial.println("\nAverage of 10 measurements by default:");
  Serial.print(sensor.getDistance());
  Serial.print(" mm");

  Serial.println("\nObstacle in given range of 500 mm found with average option on:");
  Serial.print(sensor.getObstacle(500));

  Serial.println("\nObstacle in given range of 500 mm found with average option off:");
  Serial.print(sensor.getObstacle(500,false));
  delay(1000);
}