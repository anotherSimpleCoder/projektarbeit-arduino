#include <Arduino.h>
#include "Increment1.h"

const int RED_LED_PIN = 10;
const int GREEN_LED_PIN = 11;

void redBlink() {
  digitalWrite(RED_LED_PIN, HIGH);
  delay(2000);
  digitalWrite(RED_LED_PIN, LOW);
  delay(2000);
}

void greenBlink() {
  digitalWrite(GREEN_LED_PIN, HIGH);
  delay(2000);
  digitalWrite(GREEN_LED_PIN, LOW);
  delay(2000);
}

void setup() {
  pinMode(RED_LED_PIN, OUTPUT);
  pinMode(GREEN_LED_PIN, OUTPUT);
}

void loop() { 
  redBlink();
  greenBlink();
}
