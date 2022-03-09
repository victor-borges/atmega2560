#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include "header.h"
#include "pitches.h"

#define PIEZO_BUZZER 8

void setup() {
    pinMode(PIEZO_BUZZER, OUTPUT);
    xTaskCreate(play_melody, "play_melody", 128, NULL, 2, NULL);
}

void loop() {
    // Empty on purpose
}

int melody[] = {NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4};
int noteDurations[] = {4, 8, 8, 4, 4, 4, 4, 4};

void play_melody(void *parameters) {
    (void) parameters;

    // iterate over the notes of the melody:
    for (int note = 0; note < 8; note++) {
        // to calculate the note duration, take one second divided by the note type.
        //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
        int noteDuration = 1000 / noteDurations[note];

        tone(PIEZO_BUZZER, melody[note], noteDuration);

        // to distinguish the notes, set a minimum time between them.
        // the note's duration + 30% seems to work well:
        int pauseBetweenNotes = noteDuration * 1.30;

        delay(pauseBetweenNotes);

        // stop the tone playing:
        noTone(PIEZO_BUZZER);
    }
}
