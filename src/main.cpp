#include <Arduino.h>
#include <SPI.h>
#include <MFRC522.h>

MFRC522 mfrc522(10, 9);

void setup() {
  Serial.begin(9600);
  Serial.println("RFID Ready");
  SPI.begin();
  mfrc522.PCD_Init();
}

void loop() {
  // Test output every 5 seconds to verify communication
  static unsigned long lastHeartbeat = 0;
  if (millis() - lastHeartbeat > 5000) {
    Serial.println("Arduino alive");
    lastHeartbeat = millis();
  }
  
  if (!mfrc522.PICC_IsNewCardPresent()) return;
  if (!mfrc522.PICC_ReadCardSerial()) return;
  
  // Format UID for Flask server parsing
  String uid = "";
  for (byte i = 0; i < mfrc522.uid.size; i++) {
    if (i > 0) uid += ":";
    if (mfrc522.uid.uidByte[i] < 0x10) uid += "0";
    uid += String(mfrc522.uid.uidByte[i], HEX);
  }
  Serial.println("UID: " + uid);
  
  mfrc522.PICC_HaltA();
  delay(1000);
}
