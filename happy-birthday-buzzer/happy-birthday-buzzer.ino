// -------------------------------------------------
// Copyright (c) 2022 HiBit <https://www.hibit.dev>
// -------------------------------------------------

#include "pitches.h"

#define BUZZER_PIN 9
#define LED 13

int melody[] = {
  NOTE_C4, NOTE_C4,
  NOTE_D4, NOTE_C4, NOTE_F4,
  NOTE_E4, NOTE_C4, NOTE_C4,
  NOTE_D4, NOTE_C4, NOTE_G4,
  NOTE_F4, NOTE_C4, NOTE_C4,

  NOTE_C5, NOTE_A4, NOTE_F4,
  NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4,
  NOTE_A4, NOTE_F4, NOTE_G4,
  NOTE_F4
};

int durations[] = {
  4, 8,
  4, 4, 4,
  2, 4, 8,
  4, 4, 4,
  2, 4, 8,

  4, 4, 4,
  4, 4, 4, 8,
  4, 4, 4,
  2
};

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int size = sizeof(durations) / sizeof(durations[0]);

  for (int note = 0; note < size; note++) {
    int duration = 1000 / durations[note];

    // Play the note
    tone(BUZZER_PIN, melody[note], duration);
    digitalWrite(LED, HIGH); // Turn LED ON
    delay(duration * 1.30);  // Let the note play

    digitalWrite(LED, LOW);  // Turn LED OFF
    delay(50);  // Small gap between notes
  }

  noTone(BUZZER_PIN); // Stop the buzzer
  delay(2000); // Pause before repeating the melody
}
