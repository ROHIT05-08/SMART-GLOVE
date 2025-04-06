#include <SoftwareSerial.h>

SoftwareSerial BTSerial(10, 11); // RX, TX for HC-05

const int flex1Pin = A0; // Flex sensor 1
const int flex2Pin = A1; // Flex sensor 2

const int flexThreshold = 950; // Updated threshold

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);

  Serial.println("Flex sensor message mode ready!");
  BTSerial.println("Bluetooth connected.");
}

void loop() {
  int flex1Value = analogRead(flex1Pin);
  int flex2Value = analogRead(flex2Pin);

  // Print values to Serial Monitor (for testing)
  Serial.print("Flex 1: ");
  Serial.print(flex1Value);
  Serial.print(" | Flex 2: ");
  Serial.println(flex2Value);

  // If Flex 1 is bent beyond threshold
  if (flex1Value > flexThreshold) {
    BTSerial.println("Need Water");
    Serial.println("Sent: Need Water");
    delay(3000); // debounce delay
  }

  // If Flex 2 is bent beyond threshold
  if (flex2Value > flexThreshold) {
    BTSerial.println("Good Morning");
    Serial.println("Sent: Good Morning");
    delay(3000); // debounce delay
  }

  delay(1000); // sampling delay
}
