#!/bin/bash

writeDiagram() {
    echo "{" >> diagram.json
    echo "\"version\": 1," >> diagram.json
    echo "\"author\": \"Anonymous maker\"," >> diagram.json
    echo "\"editor\": \"wokwi\"," >> diagram.json
    echo "\"parts\": [ { \"id\": \"uno\", \"type\": \"wokwi-arduino-uno\" } ], " >> diagram.json
    echo "\"connections\": [] " >> diagram.json
    echo "}" >> diagram.json
}

writeToml() {
    echo "[wokwi]" >> wokwi.toml
    echo "version = 1 " >> wokwi.toml
    echo "firmware = './build/arduino.avr.uno/arduino.ino.hex'" >> wokwi.toml
    echo "elf = './build/arduino.avr.uno/arduino.ino.elf'" >> wokwi.toml
}

writeMakefile() {
    echo "compile: " >> Makefile
    echo "\tarduino-cli compile --fqbn arduino:avr:uno -e arduino.ino" >> Makefile
    echo "upload: " >> Makefile
    echo "\tarduino-cli upload -p /dev/ttyACM0 --fqbn arduino:avr:uno arduino.ino" >> Makefile
}

writeEditorConfig() {
    echo "root = true" >> .editorconfig
    echo >> .editorconfig
    echo "[*]" >> .editorconfig
    echo "indent_space = space" >> .editorconfig
    echo "indent_size = 2" >> .editorconfig
}

echo ===================
echo Arduino CLI + Wokwi 
echo ===================
echo
read -p "Enter your sketch name: " projName
echo Generating $projName

arduino-cli sketch new $projName

(
    cd $projName
    writeDiagram
    writeToml
    writeMakefile
    writeEditorConfig
)