$AVRDUDE="C:\Users\abav\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/bin/avrdude" 
$CONF="C:\Users\abav\AppData\Local\Arduino15\packages\arduino\tools\avrdude\6.3.0-arduino17/etc/avrdude.conf"


& $AVRDUDE `
    "-C$CONF" `
    -v -V -patmega328p  `
    -carduino "-PCOM5"  `
    -b115200  `
    -D "-Uflash:w:Increment1.ino.hex:i"