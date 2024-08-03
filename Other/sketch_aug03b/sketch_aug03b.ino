#include <SoftwareSerial.h>

// Create a new software serial port on pins 10 (RX) and 11 (TX)
SoftwareSerial BTSerial(6, 5); // RX, TX

void setup() {
  // Initialize serial communication at 9600 baud rate for Serial Monitor
  Serial.begin(9600);
  
  // Initialize serial communication at 9600 baud rate for Bluetooth module
  BTSerial.begin(9600);
  
  // Print a message to the Serial Monitor
  Serial.println("Bluetooth module is ready to receive commands.");
}

void loop() {
  // Check if data is available from the Bluetooth module
  if (BTSerial.available()) {
    // Read the incoming data from the Bluetooth module
    String command = BTSerial.readStringUntil('\n');
    
    // Print the received command to the Serial Monitor
    Serial.print("Received command: ");
    Serial.println(command);
  }
}
