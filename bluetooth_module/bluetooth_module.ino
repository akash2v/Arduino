#include <SoftwareSerial.h>

#define BT_TX 11  // Arduino TX (connects to HC-05 RXD)
#define BT_RX 10  // Arduino RX (connects to HC-05 TXD)

SoftwareSerial BTSerial(BT_TX, BT_RX); // SoftwareSerial for Bluetooth

void setup() {
  Serial.begin(9600);   // Serial Monitor
  BTSerial.begin(9600); // Bluetooth Module

  Serial.println("HC-05 Bluetooth Module Ready hai!");
}

void loop() {
  if (BTSerial.available()) {  // If data is received from Bluetooth
    char data = BTSerial.read();
    Serial.print("Received from Bluetooth: ");
    Serial.println(data);
    
    // Send response back to Bluetooth
    BTSerial.print("Echo: ");
    BTSerial.println(data);
  }

  if (Serial.available()) {  // If data entered in Serial Monitor
    char data = Serial.read();
    BTSerial.write(data);  // Send to Bluetooth module
  }
}
