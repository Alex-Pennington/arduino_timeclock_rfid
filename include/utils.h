// Utility functions for Arduino RFID Time Clock System
#ifndef UTILS_H
#define UTILS_H

#include "config.h"

// Time formatting utilities
void formatTime(unsigned long timestamp, char* buffer) {
  unsigned long seconds = timestamp / 1000;
  unsigned long minutes = seconds / 60;
  unsigned long hours = minutes / 60;
  
  seconds %= 60;
  minutes %= 60;
  hours %= 24;
  
  sprintf(buffer, "%02lu:%02lu:%02lu", hours, minutes, seconds);
}

void formatDate(unsigned long timestamp, char* buffer) {
  // Simple date formatting (days since start)
  unsigned long days = timestamp / (24UL * 60UL * 60UL * 1000UL);
  sprintf(buffer, "Day %lu", days);
}

// String utilities
void centerText(char* text, char* buffer, int width) {
  int len = strlen(text);
  int padding = (width - len) / 2;
  
  memset(buffer, ' ', width);
  buffer[width] = '\0';
  
  if (len <= width) {
    strncpy(buffer + padding, text, len);
  } else {
    strncpy(buffer, text, width);
  }
}

void truncateText(const char* source, char* dest, int maxLen) {
  if (strlen(source) <= (size_t)maxLen) {
    strcpy(dest, source);
  } else {
    strncpy(dest, source, maxLen - 3);
    dest[maxLen - 3] = '.';
    dest[maxLen - 2] = '.';
    dest[maxLen - 1] = '.';
    dest[maxLen] = '\0';
  }
}

// UID comparison utility
bool compareUID(byte uid1[4], byte uid2[4]) {
  for (int i = 0; i < 4; i++) {
    if (uid1[i] != uid2[i]) {
      return false;
    }
  }
  return true;
}

// UID to string conversion
void uidToString(byte uid[4], char* buffer) {
  sprintf(buffer, "%02X%02X%02X%02X", uid[0], uid[1], uid[2], uid[3]);
}

// Memory utilities
int getFreeMemory() {
  extern int __heap_start, *__brkval;
  int v;
  return (int) &v - (__brkval == 0 ? (int) &__heap_start : (int) __brkval);
}

// Button reading utility (for HW-555 LCD shield)
ButtonState readButton() {
  int reading = analogRead(BTN_ANALOG_PIN);
  
  if (reading < BTN_RIGHT_VAL + BTN_TOLERANCE) {
    return BTN_RIGHT;
  } else if (reading < BTN_UP_VAL + BTN_TOLERANCE) {
    return BTN_UP;
  } else if (reading < BTN_DOWN_VAL + BTN_TOLERANCE) {
    return BTN_DOWN;
  } else if (reading < BTN_LEFT_VAL + BTN_TOLERANCE) {
    return BTN_LEFT;
  } else if (reading < BTN_SELECT_VAL + BTN_TOLERANCE) {
    return BTN_SELECT;
  }
  
  return BTN_NONE;
}

// Validation utilities
bool isValidName(const char* name) {
  if (strlen(name) == 0 || strlen(name) >= MAX_NAME_LENGTH) {
    return false;
  }
  
  // Check for valid characters (letters, numbers, spaces)
  for (size_t i = 0; i < strlen(name); i++) {
    char c = name[i];
    if (!((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || 
          (c >= '0' && c <= '9') || c == ' ')) {
      return false;
    }
  }
  
  return true;
}

// Progress bar utility for LCD
void drawProgressBar(int progress, int total, char* buffer) {
  int barWidth = 14; // Leave 2 chars for brackets
  int filledChars = (progress * barWidth) / total;
  
  buffer[0] = '[';
  for (int i = 1; i <= barWidth; i++) {
    if (i <= filledChars) {
      buffer[i] = '=';
    } else {
      buffer[i] = ' ';
    }
  }
  buffer[barWidth + 1] = ']';
  buffer[barWidth + 2] = '\0';
}

// Menu navigation helpers
int wrapIndex(int index, int min, int max) {
  if (index < min) return max;
  if (index > max) return min;
  return index;
}

// Checksum calculation for data integrity
byte calculateChecksum(byte* data, int length) {
  byte checksum = 0;
  for (int i = 0; i < length; i++) {
    checksum ^= data[i];
  }
  return checksum;
}

#endif // UTILS_H