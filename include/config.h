// Configuration file for Arduino RFID Time Clock System
#ifndef CONFIG_H
#define CONFIG_H

// System Configuration
#define MAX_EMPLOYEES 10
#define MAX_NAME_LENGTH 16
#define EEPROM_START_ADDR 0
#define DEBOUNCE_DELAY 200
#define MESSAGE_DISPLAY_TIME 3000
#define CARD_DEBOUNCE_TIME 10000  // 10 seconds between card reads

// Pin Configuration for RC522 RFID Module
#define RC522_SS_PIN 10
#define RC522_RST_PIN 9

// Additional pins available with I2C LCD Shield
#define BUZZER_PIN 8       // Moved from 9 (now used for RC522 RST)
#define AUDIO_PIN 6        // PWM pin for Mario sound effects
#define LED_RED_PIN 7      // Moved from 8
#define LED_GREEN_PIN 5    // Moved from 7

// HW-555 LCD Shield I2C Configuration
#define LCD_I2C_ADDR 0x27
#define LCD_COLS 16
#define LCD_ROWS 2
#define LCD_D4_PIN 5
#define LCD_D5_PIN 4
#define LCD_D6_PIN 3
#define LCD_D7_PIN 2

// HW-555 LCD Shield Button Configuration (Analog read from A0)
#define BTN_ANALOG_PIN A0

// HW-555 LCD Shield Button Threshold Values
#define BTN_RIGHT_VAL 0
#define BTN_UP_VAL 99
#define BTN_DOWN_VAL 256
#define BTN_LEFT_VAL 410
#define BTN_SELECT_VAL 640
#define BTN_NONE_VAL 1023
#define BTN_TOLERANCE 50

// Audio Feedback Configuration
#define BEEP_CLOCK_IN_FREQ 2000
#define BEEP_CLOCK_OUT_FREQ 1500
#define BEEP_ERROR_FREQ 1000
#define BEEP_DURATION 200

// Mario Sound Effect Frequencies (in Hz)
#define NOTE_E6  1319
#define NOTE_E7  2637
#define NOTE_A6  1760
#define NOTE_B6  1976
#define NOTE_AS6 1865
#define NOTE_C7  2093
#define NOTE_D7  2349
#define NOTE_G6  1568
#define NOTE_G7  3136
#define NOTE_F6  1397
#define NOTE_C6  1047
#define NOTE_D6  1175

// Dungeon/Error Sound Frequencies
#define NOTE_C4  262
#define NOTE_G3  196
#define NOTE_F3  175
#define NOTE_E3  165

// Display Configuration
#define LCD_COLS 16
#define LCD_ROWS 2
#define SCROLL_DELAY 500

// EEPROM Memory Layout
#define EEPROM_EMPLOYEE_COUNT_ADDR 0
#define EEPROM_EMPLOYEES_START_ADDR 1
#define EEPROM_HISTORY_START_ADDR 500

// System States
enum SystemState {
  STATE_READY,
  STATE_SCANNING,
  STATE_PROCESSING,
  STATE_ADMIN_MODE,
  STATE_ERROR
};

// Menu System
enum MenuState {
  MENU_MAIN,
  MENU_ADMIN,
  MENU_ADD_EMPLOYEE,
  MENU_VIEW_EMPLOYEES,
  MENU_CLOCK_HISTORY,
  MENU_SETTINGS,
  MENU_DELETE_EMPLOYEE
};

// Button States
enum ButtonState {
  BTN_NONE,
  BTN_SELECT,
  BTN_LEFT,
  BTN_UP,
  BTN_DOWN,
  BTN_RIGHT
};

// Employee Status
enum EmployeeStatus {
  STATUS_CLOCKED_OUT,
  STATUS_CLOCKED_IN,
  STATUS_INACTIVE
};

#endif // CONFIG_H