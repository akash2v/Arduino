int buzzer = 9;  // Buzzer connected to pin 9
int led = 13;    // LED connected to pin 13

// Notes for "Twinkle Twinkle Little Star"
int melody[] = { 262, 262, 392, 392, 440, 440, 392, 0,
                 349, 349, 330, 330, 294, 294, 262, 0 };

// Note durations (4 = quarter note, 8 = eighth note, etc.)
int noteDurations[] = { 4, 4, 4, 4, 4, 4, 2, 4,
                         4, 4, 4, 4, 4, 4, 2, 4 };

void setup() {
  pinMode(buzzer, OUTPUT);
  pinMode(led, OUTPUT);
}

void loop() {
  for (int i = 0; i < 16; i++) {
    int noteDuration = 1000 / noteDurations[i]; // Convert to milliseconds
    
    if (melody[i] > 0) { // If not a pause
      tone(buzzer, melody[i], noteDuration);
      digitalWrite(led, HIGH);
    } else {
      noTone(buzzer);
      digitalWrite(led, LOW);
    }
    
    delay(noteDuration * 1.3); // Pause between notes
    digitalWrite(led, LOW); // Turn off LED after note
  }

  delay(2000); // Wait before playing again
}
