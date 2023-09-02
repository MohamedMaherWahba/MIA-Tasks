#include <Wire.h>

const int buttonPin1 = 2;  // Pin for the first button
const int buttonPin2 = 3;  // Pin for the second button

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);
  pinMode(buttonPin2, INPUT_PULLUP);
  
  Wire.begin();  // Initialize I2C communication
}

void loop() {
  // Read the state of the buttons
  int buttonState1 = digitalRead(buttonPin1);
  int buttonState2 = digitalRead(buttonPin2);
  
  // Prepare data to be sent over I2C
  byte buttonData = (buttonState1 << 1) | buttonState2;

  // Send button data over I2C
  Wire.beginTransmission(8);  // Address of the second Arduino (receiver)
  Wire.write(buttonData);
  Wire.endTransmission();

  delay(100);  // Adjust the delay as per your requirements
}