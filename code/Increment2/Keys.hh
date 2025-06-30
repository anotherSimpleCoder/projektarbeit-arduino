#include <Keypad.h>

namespace Keys {
  const unsigned int ROWS = 4;
  const unsigned int COLS = 3;

  char keys[ROWS][COLS] = {
    {'1', '2', '3'},
    {'4', '5', '6'},
    {'7', '8', '9'},
    {'*', '0', '#'}
  };

  const byte rowPins[ROWS] = {2, 3, 4, 5};
  const byte colPins[COLS] = {6, 7, 8};

  Keypad* newKeypad() {
    return new Keypad(
        makeKeymap(keys),
        rowPins,
        colPins,
        ROWS,
        COLS
    );
  }
};
