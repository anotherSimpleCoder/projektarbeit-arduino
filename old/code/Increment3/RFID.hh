#ifndef RFID_HH
#define RFID_HH

#include <SPI.h>
#include <MFRC522.h>
#include "Leds.hh"

namespace RFID {
  const unsigned int RST_PIN = 9;
  const unsigned int SS_PIN = 10;

  uint8_t block = 0;
  uint8_t length = 15;
  uint8_t buffer[15];

  MFRC522 rfid(SS_PIN, RST_PIN);
  MFRC522::StatusCode status;
  MFRC522::MIFARE_Key key;

  void init() {
    SPI.begin();
    rfid.PCD_Init();
  }

  void authenticate() {
    for(int i = 0; i < 6; i++) key.keyByte[i] = 0xFF;

  
    if( ! rfid.PICC_IsNewCardPresent()) {
      return;
    }

    if( ! rfid.PICC_ReadCardSerial() ) {
      return;
    }


    status = rfid.PCD_Authenticate(MFRC522::PICC_CMD_MF_AUTH_KEY_A, 4, &key, &rfid.uid);
    if(status != MFRC522::STATUS_OK) {
      Serial.print(F("Authentication failed: "));
      Serial.println(rfid.GetStatusCodeName(status));
      LEDS::redBlink();
      return;
    } else {
      LEDS::greenBlink();
      Serial.println("Works!");
    }

    rfid.PICC_HaltA();
    rfid.PCD_StopCrypto1();
  }
};

#endif