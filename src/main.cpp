#include <Arduino.h>
#include <Encoder.h>
#include <Keyboard.h>


// Change these two numbers to the pins connected to your encoder.
//   Best Performance: both pins have interrupt capability
//   Good Performance: only the first pin has interrupt capability
//   Low Performance:  neither pin has interrupt capability
Encoder myEnc(2, 3);
//   avoid using pins with LEDs attached

void setup() {
  Serial.begin(9600);
  pinMode(2, INPUT);
  pinMode(3, INPUT);
}

long oldPosition  = -999;

void loop() {
  long newPosition = myEnc.read();
  if (newPosition != oldPosition) {
    while (newPosition < (oldPosition - 3)) {
      oldPosition = newPosition;
      Serial.println(newPosition);
      Serial.println("Going up/right!");
      Keyboard.press(KEY_RIGHT_ARROW);
      Keyboard.releaseAll();
    }
    while (newPosition > (oldPosition + 3)) {
      oldPosition = newPosition;
      Serial.println(newPosition);
      Serial.println("Going dowm/left!");
      Keyboard.press(KEY_LEFT_ARROW);
      Keyboard.releaseAll();
    }
  }
}