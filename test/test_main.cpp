#include <Arduino.h>
#include <unity.h>
#include "config.h"
#include "utils.h"

// Test configuration constants
void test_config_constants() {
    TEST_ASSERT_EQUAL(10, MAX_EMPLOYEES);
    TEST_ASSERT_EQUAL(16, MAX_NAME_LENGTH);
    TEST_ASSERT_EQUAL(9600, monitor_speed);  // From platformio.ini
}

// Test UID comparison utility
void test_uid_comparison() {
    byte uid1[4] = {0x12, 0x34, 0x56, 0x78};
    byte uid2[4] = {0x12, 0x34, 0x56, 0x78};
    byte uid3[4] = {0x12, 0x34, 0x56, 0x79};
    
    TEST_ASSERT_TRUE(compareUID(uid1, uid2));
    TEST_ASSERT_FALSE(compareUID(uid1, uid3));
}

// Test name validation
void test_name_validation() {
    TEST_ASSERT_TRUE(isValidName("John Doe"));
    TEST_ASSERT_TRUE(isValidName("Alice123"));
    TEST_ASSERT_FALSE(isValidName(""));  // Empty name
    TEST_ASSERT_FALSE(isValidName("VeryLongNameThatExceedsMaxLength"));  // Too long
    TEST_ASSERT_FALSE(isValidName("John@Doe"));  // Invalid character
}

// Test button value ranges
void test_button_ranges() {
    TEST_ASSERT_EQUAL(0, BTN_RIGHT_VAL);
    TEST_ASSERT_EQUAL(99, BTN_UP_VAL);
    TEST_ASSERT_EQUAL(256, BTN_DOWN_VAL);
    TEST_ASSERT_EQUAL(410, BTN_LEFT_VAL);
    TEST_ASSERT_EQUAL(640, BTN_SELECT_VAL);
    TEST_ASSERT_EQUAL(1023, BTN_NONE_VAL);
}

// Test memory layout constants
void test_memory_layout() {
    TEST_ASSERT_EQUAL(0, EEPROM_EMPLOYEE_COUNT_ADDR);
    TEST_ASSERT_EQUAL(1, EEPROM_EMPLOYEES_START_ADDR);
    TEST_ASSERT_EQUAL(500, EEPROM_HISTORY_START_ADDR);
}

void setup() {
    delay(2000);  // Wait for Serial
    
    UNITY_BEGIN();
    
    RUN_TEST(test_config_constants);
    RUN_TEST(test_uid_comparison);
    RUN_TEST(test_name_validation);
    RUN_TEST(test_button_ranges);
    RUN_TEST(test_memory_layout);
    
    UNITY_END();
}

void loop() {
    // Tests run once in setup()
}