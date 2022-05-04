#include<Arduino.h>
#include<ultrasonic.h>


void setup() {
  Serial.begin(115200);

    setSensor();
   
}

void loop() {
  float distance = runSensor();
  Serial.println(distance);
  delay(500);
}