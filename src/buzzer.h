

#include <Arduino.h>
#include <Tone32.h>

#define BUZZER_PIN 27
#define BUZZER_CHANNEL 0

void playBuzzer();

void playBuzzer()
{
    while (true)
    {
        tone(BUZZER_PIN, NOTE_B4, 100, BUZZER_CHANNEL);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
        delay(500);
        tone(BUZZER_PIN, NOTE_B4, 100, BUZZER_CHANNEL);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
        delay(500);
        tone(BUZZER_PIN, NOTE_D4, 100, BUZZER_CHANNEL);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
        delay(500);
        tone(BUZZER_PIN, NOTE_CS4, 100, BUZZER_CHANNEL);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
        delay(500);
        tone(BUZZER_PIN, NOTE_A4, 100, BUZZER_CHANNEL);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
        tone(BUZZER_PIN, NOTE_A4, 100, BUZZER_CHANNEL);
        delay(500);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
        tone(BUZZER_PIN, NOTE_B4, 100, BUZZER_CHANNEL);
        delay(500);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
        tone(BUZZER_PIN, NOTE_B4, 100, BUZZER_CHANNEL);
        delay(500);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
        tone(BUZZER_PIN, NOTE_D4, 100, BUZZER_CHANNEL);
        delay(500);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
        tone(BUZZER_PIN, NOTE_CS4, 100, BUZZER_CHANNEL);
        delay(500);
        noTone(BUZZER_PIN, BUZZER_CHANNEL);
        tone(BUZZER_PIN, NOTE_A4, 100, BUZZER_CHANNEL);
        delay(500);
    }
}
