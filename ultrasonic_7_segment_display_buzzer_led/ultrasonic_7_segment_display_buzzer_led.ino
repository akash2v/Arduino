#include <SoftwareSerial.h>

#define BT_TX 10  // Bluetooth TX to Arduino RX
#define BT_RX 11  // Bluetooth RX to Arduino TX

SoftwareSerial BTSerial(BT_TX, BT_RX); // Create Bluetooth Serial

void setup() {
  Serial.begin(9600);      // Serial Monitor
  BTSerial.begin(9600);    // Bluetooth module communication (Default: 9600)

  Serial.println("Bluetooth Module Ready!");
}

void loop() {
  // If data received from Bluetooth, send to Serial Monitor
  if (BTSerial.available()) {
    char data = BTSerial.read();
    Serial.print("Received: ");
    Serial.println(data);
    
    // Send back the received data (Echo)
    BTSerial.print("Echo: ");
    BTSerial.println(data);
  }

  // If data entered in Serial Monitor, send to Bluetooth module
  if (Serial.available()) {
    char data = Serial.read();
    BTSerial.write(data);
  }
}
