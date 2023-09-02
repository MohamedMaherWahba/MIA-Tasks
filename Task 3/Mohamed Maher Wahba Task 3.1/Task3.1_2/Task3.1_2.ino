#include <Wire.h>

const int buttonReceiverAddress = 8;   // Address of this Arduino (receiver)
const int ledPin = 9;                  // Pin for the indicator LED

void setup() {
  pinMode(ledPin, OUTPUT);
  
  Wire.begin(buttonReceiverAddress);  // Initialize I2C communication with the receiver address
  Wire.onReceive(receiveEvent);       // Register the receive event handler
  Serial.begin(9600);                 // Initialize serial communication for debugging (optional)
}

void loop() {
  
}

// I2C receive event handler
void receiveEvent(int byteCount) {
  if (byteCount >= 1) {
    byte buttonData = Wire.read();  // Read the received button data
    
    // Extract the state of the buttons
    int buttonState1 = (buttonData >> 1) & 0x01;
    int buttonState2 = buttonData & 0x01;
    
    // Process the button states and control the LED intensity
    if (buttonState1 == 0 && buttonState2 == 0) {
      // B1=0, B2=0 - 0% of Maximum - No message
      analogWrite(ledPin, 0);  // Turn off the LED
      Serial.println("0% of Maximum - No message");
    } else if (buttonState1 == 1 && buttonState2 == 0) {
      // B1=1, B2=0 - 50% of Maximum - Vector focused
      analogWrite(ledPin, 128);  // Set LED intensity to 50% (128/255)
      Serial.println("50% of Maximum - Vector focused");
    } else if (buttonState1 == 0 && buttonState2 == 1) {
      // B1=0, B2=1 - 75% of Maximum - Vector distracted
      analogWrite(ledPin, 192);  // Set LED intensity to 75% (192/255)
      Serial.println("75% of Maximum - Vector distracted");
    } else if (buttonState1 == 1 && buttonState2 == 1) {
      // B1=1, B2=1 - 100% of Maximum - Glitch
      analogWrite(ledPin, 255);  // Set LED intensity to 100% (255/255)
      Serial.println("100% of Maximum - Glitch");
    }
  }
}