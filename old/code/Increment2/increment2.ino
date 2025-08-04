#include "Leds.hh"
#include "Keys.hh"
#include "String.hh"

const Keypad* keypad;
char pinCode[4] = "1473";
char buffer[4];
int i = 0;

void setup() {
  Serial.begin(9600);
  pinMode(LEDS::RED_LED_PIN, OUTPUT);
  pinMode(LEDS::GREEN_LED_PIN, OUTPUT);
  keypad = Keys::newKeypad();
}

void loop() {
  char key = keypad->getKey();
  if(!key) return;

  if(key == '#') {
    bool equal = Strings::equals(pinCode, buffer);
    
    if(equal) {
      LEDS::greenBlink();
    } else {
      LEDS::redBlink();
    }

    i = 0;
    Strings::clear(buffer);
  } else if(i < 4) {
    Serial.println(key);
    buffer[i] = key;
    i++;
  }
}
