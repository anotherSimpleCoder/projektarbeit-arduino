#include "Keys.hh"
#include "RFID.hh"

void setup() {
  Serial.begin(9600);
  pinMode(LEDS::RED_LED_PIN, OUTPUT);
  //pinMode(LEDS::GREEN_LED_PIN, OUTPUT);
  Keys::init();
  //RFID::init();
}

void loop() {
  Keys::authenticate();
  //RFID::authenticate();
}
