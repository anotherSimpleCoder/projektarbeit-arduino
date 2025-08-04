$CC="C:\Users\abav\AppData\Local\Arduino15\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-gcc"
$CXX="C:\Users\abav\AppData\Local\Arduino15\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++"
$OBJCOPY="C:\Users\abav\AppData\Local\Arduino15\packages\arduino\tools\avr-gcc\7.3.0-atmel3.6.1-arduino7/bin/avr-g++"

& $CXX 
    -c -g -Os -w `
    -std=gnu++11 `
    -fpermissive -fno-exceptions `
    -ffunction-sections -fdata-sections -fno-threadsafe-statics `
    -Wno-error=narrowing -flto -w `
    -x c++ -E -CC `
    -mmcu=atmega328p `
    -DF_CPU=16000000L `
    -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR `
    -I./lib/ArduinoCore-avr/cores/arduino `
    -I./lib/ArduinoCore-avr//variants/standard `
    Increment1.ino `
    -o /dev/null

Write-Host "Preprocessed!"

& $CXX `
    -c -g -Os -w `
    -std=gnu++11 `
    -fpermissive -fno-exceptions `
    -ffunction-sections -fdata-sections -fno-threadsafe-statics `
    -Wno-error=narrowing -flto -w `
    -x c++ -E -CC `
    -mmcu=atmega328p `
    -DF_CPU=16000000L `
    -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR `
    -I./lib/ArduinoCore-avr/cores/arduino `
    -I./lib/ArduinoCore-avr//variants/standard `
    Increment1.ino `
    -o merged.cpp

Write-Host "Merged!"

& $CXX -c -g -Os -w `
    -std=gnu++11 `
    -fpermissive -fno-exceptions `
    -ffunction-sections -fdata-sections -fno-threadsafe-statics `
    -Wno-error=narrowing -MMD -flto `
    -mmcu=atmega328p `
    -DF_CPU=16000000L `
    -DARDUINO=10607 -DARDUINO_AVR_UNO -DARDUINO_ARCH_AVR `
    -I./lib/ArduinoCore-avr/cores/arduino `
    -I./lib/ArduinoCore-avr//variants/standard `
    merged.cpp `
    -o merged.o

Write-Host "Compiled!"

& $CC -w -Os -g `
    -flto `
    -fuse-linker-plugin `
    -Wl --gc-sections `
    -mmcu=atmega328p `
    -o Increment1.ino.elf `
    merged.o `
    /home/amsakan/.cache/arduino/sketches/757C4BE98FC22B7CE1AB224DA15F72B9/../../cores/arduino_avr_uno_66e16a98b755b1b0ee421858be42c689/core.a `
    -L/home/amsakan/.cache/arduino/sketches/757C4BE98FC22B7CE1AB224DA15F72B9 -lm

Write-Host "Linked!"

& $OBJCOPY `
    -O ihex -j .eeprom `
    --set-section-flags=.eeprom=alloc,load `
    --no-change-warnings --change-section-lma .eeprom=0 `
    Increment1.ino.elf `
    Increment1.ino.eep

& $OBJCOPY `
    -O ihex -R .eeprom `
    Increment1.ino.elf `
    Increment1.ino.hex

rm merged.*