compile:
	doas arduino-cli compile --fqbn arduino:avr:uno -e Increment2.ino
	doas arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno Increment2.ino
