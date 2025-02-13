#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER 5

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER, OUTPUT);
}

// Function to make the buzzer beep
void beepBuzzer(int duration, int interval) {
  for (int i = 0; i < 5; i++) {  // Beep 5 times
    digitalWrite(BUZZER, HIGH);
    delay(duration);  // Beep duration
    digitalWrite(BUZZER, LOW);
    delay(interval);  // Pause between beeps
  }
}

void loop() {
  long duration;
  float distance;

  // Ensure a clean signal
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);

  // Send a 10µs pulse to trigger the measurement
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  // Measure the echo pulse duration
  duration = pulseIn(ECHO_PIN, HIGH);

  // Convert duration to distance
  distance = (duration * 0.0343) / 2;

  if (distance >= 2 && distance <= 400) { // Object detected in range
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
    digitalWrite(BUZZER, LOW);  // Ensure buzzer is OFF when object is in range
  } else {
    Serial.println("Out of range");
    beepBuzzer(100, 100); // Call buzzer function when out of range
  }

  delay(500); // Wait before the next measurement
}
