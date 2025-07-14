#include "Leds.hh"
#include "Keys.hh"

const Keypad* keypad;

void setup() {
  pinMode(LEDS::RED_LED_PIN, OUTPUT);
  pinMode(LEDS::GREEN_LED_PIN, OUTPUT);
  keypad = Keys::newKeypad();
}

void loop() {
  char key = keypad->getKey();
  if(!key) return;

  if(key == '#') {
    LEDS::greenBlink(); 
  }
}
