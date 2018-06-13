#include <Arduino.h>
#include <HCSR04.h>

//global debug flag
#define DEBUG

//pin configuration
#define FRONT_SENSOR_TRIGGER_PIN    13
#define FRONT_SENSOR_ECHO_PIN       12

HCSR04 frontSensor (
  FRONT_SENSOR_TRIGGER_PIN,
  FRONT_SENSOR_ECHO_PIN
);        

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
    Serial.print(" mm");

    Serial.println("\nAverage of 10 measurements by default:");
    Serial.print(frontSensor.getDistance());
    Serial.print(" mm");

    Serial.println("\nObstacle in given range of 500 mm found with average option on:");
    Serial.print(frontSensor.getObstacle(500));

    Serial.println("\nObstacle in given range of 500 mm found with average option off:");
    Serial.print(frontSensor.getObstacle(500,false));
  #endif
  delay(1000);
}