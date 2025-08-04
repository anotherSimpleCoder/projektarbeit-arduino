#ifndef LEDS_HH
#define LEDS_HH

namespace LEDS {
	const int RED_LED_PIN = 9;
	const int GREEN_LED_PIN = 9;

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
};

#endif