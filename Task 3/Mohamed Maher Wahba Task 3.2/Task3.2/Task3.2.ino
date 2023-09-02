#include <NewPing.h>

// Pin definitions for ultrasonic sensors
#define TRIGGER_PIN_1 2
#define ECHO_PIN_1 3
#define TRIGGER_PIN_2 4
#define ECHO_PIN_2 5
#define TRIGGER_PIN_3 6
#define ECHO_PIN_3 7
#define TRIGGER_PIN_4 8
#define ECHO_PIN_4 9

// Initialize ultrasonic sensors
NewPing sonar1(TRIGGER_PIN_1, ECHO_PIN_1, 800);
NewPing sonar2(TRIGGER_PIN_2, ECHO_PIN_2, 800);
NewPing sonar3(TRIGGER_PIN_3, ECHO_PIN_3, 800);
NewPing sonar4(TRIGGER_PIN_4, ECHO_PIN_4, 800);

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Measure distance using ultrasonic sensors
  unsigned int duration1 = sonar1.ping_median();
  unsigned int duration2 = sonar2.ping_median();
  unsigned int duration3 = sonar3.ping_median();
  unsigned int duration4 = sonar4.ping_median();

  // Calculate the position of the cookie bot
  float x = 0.0;
  float y = 0.0;
  
  // Determine the x-coordinate
  if (duration1 < 800) {  
    x = 5.0 - (duration1 * 0.0343 / 2);
  } else if (duration3 < 800) {
    x = 0.0 + (duration3 * 0.0343 / 2);
  }
  
  // Determine the y-coordinate
  if (duration2 < 800) {
    y = 6.0 - (duration2 * 0.0343 / 2);
  } else if (duration4 < 800) {
    y = 0.0 + (duration4 * 0.0343 / 2);
  }
  
  // Print the coordinates
  Serial.print("Cookie Bot Position (x, y): ");
  Serial.print(x);
  Serial.print(", ");
  Serial.println(y);
  
  delay(1000); // Delay between measurements
}
