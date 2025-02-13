int ledPin = 13; // LED connected to pin 13
int buzzerPin = 9; // Buzzer connected to pin 9

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);  // Turn LED ON
  digitalWrite(buzzerPin, LOW); // Turn buzzer ON
  delay(500);  // Wait 500ms

  digitalWrite(ledPin, LOW);   // Turn LED OFF
  digitalWrite(buzzerPin, HIGH);  // Turn buzzer OFF
  delay(500);  // Wait 500ms
}
