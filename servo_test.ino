#include <Servo.h>

#define SERVO_PIN 13

Servo myServo;  // Create a Servo object

void setup() {
  myServo.attach(SERVO_PIN); // Attach servo to pin 13
  myServo.write(0);  // Set initial position to 0°
}

void loop() {
  myServo.write(0);   // Move to 0°
  delay(1000);        // Wait for 1 second

  myServo.write(90);  // Move to 90°
  delay(1000);        // Wait for 1 second

  myServo.write(180); // Move to 180°
  delay(1000);        // Wait for 1 second
}
