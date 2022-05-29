

#include <Arduino.h>
#include <Tone32.h>

#define BUZZER_CHANNEL 0

void setBuzzer(const int pin);
void playBuzzer(int BuzzerPin);
void stopBuzzer(int BuzzerPin);

void setBuzzer(const int pin)
{
    pinMode(pin, OUTPUT);
}
void playBuzzer(int BuzzerPin)
{
    
        tone(BuzzerPin, NOTE_B4, 100, BUZZER_CHANNEL);
        noTone(BuzzerPin, BUZZER_CHANNEL);
        delay(500);
        tone(BuzzerPin, NOTE_B4, 100, BUZZER_CHANNEL);
        noTone(BuzzerPin, BUZZER_CHANNEL);
        delay(500);
        tone(BuzzerPin, NOTE_D4, 100, BUZZER_CHANNEL);
        noTone(BuzzerPin, BUZZER_CHANNEL);
        delay(500);
        tone(BuzzerPin, NOTE_CS4, 100, BUZZER_CHANNEL);
        noTone(BuzzerPin, BUZZER_CHANNEL);
        delay(500);
        tone(BuzzerPin, NOTE_A4, 100, BUZZER_CHANNEL);
        noTone(BuzzerPin, BUZZER_CHANNEL);
        tone(BuzzerPin, NOTE_A4, 100, BUZZER_CHANNEL);
        delay(500);
        noTone(BuzzerPin, BUZZER_CHANNEL);
        tone(BuzzerPin, NOTE_B4, 100, BUZZER_CHANNEL);
        delay(500);
        noTone(BuzzerPin, BUZZER_CHANNEL);
        tone(BuzzerPin, NOTE_B4, 100, BUZZER_CHANNEL);
        delay(500);
        noTone(BuzzerPin, BUZZER_CHANNEL);
        tone(BuzzerPin, NOTE_D4, 100, BUZZER_CHANNEL);
        delay(500);
        noTone(BuzzerPin, BUZZER_CHANNEL);
        tone(BuzzerPin, NOTE_CS4, 100, BUZZER_CHANNEL);
        delay(500);
        noTone(BuzzerPin, BUZZER_CHANNEL);
        tone(BuzzerPin, NOTE_A4, 100, BUZZER_CHANNEL);
        delay(500);
    
}

void stopBuzzer(int BuzzerPin)
{
    noTone(BuzzerPin, BUZZER_CHANNEL);
}
