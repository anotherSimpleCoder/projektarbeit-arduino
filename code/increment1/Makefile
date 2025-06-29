compile:
	doas arduino-cli compile --fqbn arduino:avr:uno -e code.ino
	doas arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno code.ino
