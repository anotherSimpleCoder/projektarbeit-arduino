#ifndef KEYS_HH
#define KEYS_HH

#include <Keypad.h>
#include "Leds.hh"
#include "String.hh"

namespace Keys {
  const Keypad* keypad;

  const unsigned int ROWS = 4;
  const unsigned int COLS = 3;

  const char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
  };

  const byte rowPins[ROWS] = {2, 3, 4, 5};
  const byte colPins[COLS] = {6, 7, 8};

  const char pinCode[4] = "1111";
  char buffer[4];
  int bufferIndex = 0;


  Keypad* newKeypad() {
    return new Keypad(
        makeKeymap(keys),
        rowPins,
        colPins,
        ROWS,
        COLS
    );
  }

  void init() {
    keypad = Keys::newKeypad();
  }

  void authenticate() {
    char key = keypad->getKey();
    if(!key) return;

    if(key == '#') {
      bool equal = Strings::equals(pinCode, buffer);
      
      if(equal) {
        Serial.println("Correct!");
        LEDS::greenBlink();
      } else {
        Serial.println("Wrong!");
        LEDS::redBlink();
      }

      bufferIndex = 0;
      Strings::clear(buffer);
    } else if(bufferIndex < 4) {
      Serial.println(key);
      buffer[bufferIndex] = key;
      bufferIndex++;
    }
  }
};

#endif