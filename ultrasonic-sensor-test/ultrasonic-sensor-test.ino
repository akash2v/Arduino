#define TRIG_PIN 9
#define ECHO_PIN 10

void setup() {
  Serial.begin(9600);
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
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

  if (distance >= 2 && distance <= 400) { // Sensor range
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");
  } else {
    Serial.println("Out of range");
  }

  delay(500);
}
