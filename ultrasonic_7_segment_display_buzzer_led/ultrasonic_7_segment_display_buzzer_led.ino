#include <Servo.h>

#define TRIG_PIN 9
#define ECHO_PIN 10
#define BUZZER 5
#define SERVO_PIN 12

#define a 7
#define b 6
#define c 2
#define d 4
#define e 3
#define f 8
#define g 11

Servo myServo;
int arr[7] = { a, b, c, d, e, f, g };

// Lookup table for digits 0-9 (1 means ON, 0 means OFF)
const byte digits[10][7] = {
  { 1, 1, 1, 1, 1, 1, 0 },  // 0
  { 0, 1, 1, 0, 0, 0, 0 },  // 1
  { 1, 1, 0, 1, 1, 0, 1 },  // 2
  { 1, 1, 1, 1, 0, 0, 1 },  // 3
  { 0, 1, 1, 0, 0, 1, 1 },  // 4
  { 1, 0, 1, 1, 0, 1, 1 },  // 5
  { 1, 0, 1, 1, 1, 1, 1 },  // 6
  { 1, 1, 1, 0, 0, 0, 0 },  // 7
  { 1, 1, 1, 1, 1, 1, 1 },  // 8
  { 1, 1, 1, 1, 0, 1, 1 }   // 9
};

// Function to display digits on the 7-segment display
void displayDigit(int digit) {
  if (digit < 0 || digit > 9) return;  // Ensure valid input
  for (int i = 0; i < 7; i++) {
    digitalWrite(arr[i], digits[digit][i]);
  }
}

// Function to beep the buzzer
void beepBuzzer(int duration, int interval) {
  for (int i = 0; i < 5; i++) {  // Beep 5 times
    digitalWrite(BUZZER, HIGH);
    delay(duration);
    digitalWrite(BUZZER, LOW);
    delay(interval);
  }
}

void setup() {
  Serial.begin(9600);
  
  // Set pin modes
  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);
  pinMode(BUZZER, OUTPUT);

  for (int i = 0; i < 7; i++) {
    pinMode(arr[i], OUTPUT);
  }

  // Initialize servo
  myServo.attach(SERVO_PIN);
  myServo.write(0);  // Set initial position to 0°
}

void loop() {
  // Display digits and move servo
  for (int i = 0; i < 10; i++) {
    displayDigit(i);

    // Move servo based on even or odd number
    if (i % 2 == 0) {
      myServo.write(0);  // Move to 0° for even numbers
    } else {
      myServo.write(180);  // Move to 90° for odd numbers
    }

    // delay(1000);
  }

  // Ultrasonic sensor measurement
  long duration;
  float distance;

  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  duration = pulseIn(ECHO_PIN, HIGH);
  distance = (duration * 0.0343) / 2; // Convert to cm

  if (distance >= 2 && distance <= 400) {
    Serial.print("Distance: ");
    Serial.print(distance);
    Serial.println(" cm");

    if (distance >= 50 && distance <= 100) {
      beepBuzzer(50, 100); // Beep for objects 50-100 cm away
    } else {
      digitalWrite(BUZZER, LOW);
    }
  } else {
    Serial.println("Out of range");
    beepBuzzer(100, 100);
  }

  delay(500);
}
