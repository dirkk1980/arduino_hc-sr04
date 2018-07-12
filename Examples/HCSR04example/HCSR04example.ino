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
  Serial.println("------start block-------");
  Serial.println("Single measured distance:");
  Serial.println(sensor.getDistance(false));
  delay(1000);
  Serial.println("Average of 10 measurements by default:");
  Serial.println(sensor.getDistance());
  delay(1000);
  Serial.println("Average of 30 measurements defined manually:");
  Serial.println(sensor.getDistance(true,30));
  delay(1000);
  Serial.println("Obstacle in given range of 500 mm found with average option on:");
  Serial.println(sensor.getObstacle(500));
  delay(1000);
  Serial.println("Obstacle in given range of 500 mm found with average option on and 30 measurements:");
  Serial.println(sensor.getObstacle(500,true,30));
  delay(1000);
  Serial.println("Obstacle in given range of 500 mm found with average option off:");
  Serial.println(sensor.getObstacle(500,false));
  Serial.println("------end block-------");
  delay(5000);
}