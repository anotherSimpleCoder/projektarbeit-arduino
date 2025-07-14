compile:
	doas arduino-cli compile --fqbn arduino:avr:uno -e Increment1.ino
	doas arduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno Increment1.ino
