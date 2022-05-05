#include <Arduino.h>
#include <ultrasonic.h>
#include <myWifi.h>
#include<buzzer.h>

void setup()
{
    Serial.begin(115200);

    // setWifi(WIFI_SSID, WIFI_PASSWORD);
    
    // setEmailDetails(AUTHOR_EMAIL, AUTHOR_PASSWORD, RECIPIENT_EMAIL);
    // sendEmail();

    // setSensor();
}

void loop()
{
    playBuzzer();
    //enableWifiReconnect();
    //   float distance = runSensor();
    //   Serial.println(distance);
    //   delay(500);
}
