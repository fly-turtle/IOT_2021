#include "6_pitches.h"

#define BUZERPIN 6

int melody[] = {
  NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
};

int pauseBetweenNotes;

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  4, 8, 8, 4, 4, 4, 4, 4
};

int buzzer_timer; // timer 활용

void Buzzer_setup() {
  buzzer_timer = timer.setInterval(4000, Buzzer_loop);
  timer.disable(buzzer_timer);
}

void Buzzer_loop() {
  for (int thisNote = 0; thisNote < 8; thisNote++) {
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(BUZERPIN, melody[thisNote], noteDuration);
    pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(BUZERPIN);
  }
}
