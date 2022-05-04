
#include <Arduino.h>
/*
 * created by Rui Santos, https://randomnerdtutorials.com
 *
 * Complete Guide for Ultrasonic Sensor HC-SR04
 *
    Ultrasonic sensor Pins:
        VCC: +5VDC
        Trig : Trigger (INPUT) - Pin11
        Echo: Echo (OUTPUT) - Pin 12
        GND: GND
 */
// returns distance



int trigPin = 13; // globals for default
int echoPin = 12; 
float duration, cm; // distances for variables 


void setSensor();
int runSesnor();


void setSensor()
{
    
    long duration, cm;

    // Define inputs and outputs
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
}

int runSensor()
{

    digitalWrite(trigPin, LOW);
    delayMicroseconds(5);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);

    // Read the signal from the sensor: a HIGH pulse whose
    // duration is the time (in microseconds) from the sending
    // of the ping to the reception of its echo off of an object.
    pinMode(echoPin, INPUT);
    duration = pulseIn(echoPin, HIGH);


 
  
    // Convert the time into a distance
    cm = (duration / 2.0) / 29.1; // Divide by 29.1 or multiply by 0.0343
    delay(250);
    return cm;
}