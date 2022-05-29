#include <Arduino.h>
#include <ultrasonic.h>

#include <buzzer.h>
#include <AsyncTCP.h>
#include <ESPAsyncWebServer.h>

#define BUZZER_PIN 27
AsyncWebServer server(80);
String header;

#define ECHO_PIN 12
#define TRIG_PIN 13

int echoPin = 12;

// REPLACE WITH YOUR NETWORK CREDENTIALS
const char *ssid = "Kashmir house";
const char *password = "Pakistan47";

const char *PARAM_INPUT_1 = "input1";
const char *PARAM_INPUT_2 = "input2";
const char *PARAM_INPUT_3 = "input3";

void notFound(AsyncWebServerRequest *request)
{
    request->send(404, "text/plain", "Not found");
}

void setup()
{
    Serial.begin(115200);

    // setWifi(WIFI_SSID, WIFI_PASSWORD);

    // setEmailDetails(AUTHOR_EMAIL, AUTHOR_PASSWORD, RECIPIENT_EMAIL);
    // sendEmail();

    setSensor(TRIG_PIN, ECHO_PIN);
    setBuzzer(BUZZER_PIN);

    // server.begin();
}

void loop()
{
    // playBuzzer(BUZZER_PIN);
    // enableWifiReconnect();
    float distance = runSensor(TRIG_PIN, ECHO_PIN);
    Serial.println(distance);
    Serial.println("\n");
    delay(500);


    if (distance < 10)
    {
        playBuzzer(BUZZER_PIN);
        
    }
    
    
}
