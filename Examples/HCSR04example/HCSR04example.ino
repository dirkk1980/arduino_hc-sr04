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
  Serial.println("Single measured distance:");
  Serial.print(sensor.getDistance(false));
  Serial.print(" mm");
  delay(1000);
  Serial.println("Average of 10 measurements by default:");
  Serial.print(sensor.getDistance());
  Serial.print(" mm");
  delay(1000);
  Serial.println("Average of 30 measurements defined manually:");
  Serial.print(sensor.getDistance(true,30));
  Serial.print(" mm");
  delay(1000);
  Serial.println("Obstacle in given range of 500 mm found with average option on:");
  Serial.print(sensor.getObstacle(500));
  delay(1000);
  Serial.println("Obstacle in given range of 500 mm found with average option on and 30 measurements:");
  Serial.print(sensor.getObstacle(500,true,30));
  delay(1000);
  Serial.println("Obstacle in given range of 500 mm found with average option off:");
  Serial.print(sensor.getObstacle(500,false));
  delay(5000);
}