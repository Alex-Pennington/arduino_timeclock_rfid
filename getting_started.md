# Getting Started Guide

## Quick Start Checklist

### 1. Hardware Assembly
- [ ] Mount HW-555 LCD Shield directly onto Arduino Uno
- [ ] Connect Elechouse NFC V3 module to Arduino (5V power!)
- [ ] Connect LEDs with 220Ω resistors to available digital pins
- [ ] Connect buzzer for audio feedback
- [ ] Minimal external wiring due to integrated LCD shield
- [ ] Double-check all connections against wiring diagram

### 2. Software Setup (PlatformIO - Recommended)
- [ ] Install VS Code with PlatformIO IDE extension
- [ ] Open project folder in VS Code
- [ ] Libraries install automatically when building
- [ ] Build and upload: `pio run --target upload`
- [ ] Open Serial Monitor: `pio device monitor`

### 2. Software Setup (Arduino IDE Alternative)
- [ ] Install Arduino IDE
- [ ] Install required libraries manually via Library Manager
- [ ] Upload src/main.cpp to Arduino Uno
- [ ] Open Serial Monitor at 9600 baud for debugging

### 3. System Configuration
- [ ] Power on system and verify LCD displays startup message
- [ ] Test all buttons for proper response
- [ ] Enter admin mode (SELECT button) to access menu
- [ ] Add first employee by scanning RFID card
- [ ] Test clock in/out functionality

### 4. Testing Procedure
- [ ] Verify green LED indicates system ready
- [ ] Test unknown card - should show red LED and error message
- [ ] Test known card - should clock in/out with appropriate feedback
- [ ] Navigate admin menu with buttons
- [ ] Check employee data persistence after power cycle

## Daily Operation

### For Employees
1. **Clock In**: Hold RFID card near reader until beep and green flash
2. **Clock Out**: Hold same RFID card near reader for second beep and red flash
3. **Check Status**: LCD shows confirmation message for each action

### For Administrators
1. **Access Admin Menu**: Press SELECT button on main screen
2. **Add New Employee**: 
   - Navigate to "Add Employee"
   - Press SELECT to confirm
   - Scan new RFID card when prompted
   - Card will be registered automatically
3. **View Employees**: Browse registered employee list
4. **Exit Admin**: Use LEFT button or select "Exit"

## Troubleshooting Quick Reference

| Problem | Quick Fix |
|---------|-----------|
| LCD blank | Check power, adjust contrast pot |
| No RFID reading | Verify 3.3V power to MFRC522 |
| Buttons not working | Check analog pin connections |
| No audio | Verify buzzer polarity and pin 8 |
| Data lost on reset | Check EEPROM functions |

## Hardware Requirements Summary

- **Arduino Uno R3**
- **Elechouse NFC V3 Module** (5V operation)  
- **HW-555 LCD Shield** (16x2 I2C with built-in buttons)
- **2x LEDs** (Red/Green) with 220Ω resistors
- **Active Buzzer**
- **NFC/RFID Cards/Tags** for employees
- **Minimal jumper wires** (LCD shield reduces wiring complexity)

## File Structure

```
arduino_timeclock_rfid/
├── arduino_timeclock_rfid.ino  # Main Arduino sketch
├── config.h                    # Configuration constants
├── utils.h                     # Utility functions
├── README.md                   # Complete documentation
├── wiring_guide.md            # Detailed wiring instructions
├── libraries.md               # Required library information
├── getting_started.md         # This quick start guide
└── .github/
    └── copilot-instructions.md # Development guidelines
```

## Next Steps

After successful setup:
1. **Expand Employee Database**: Add more employees as needed
2. **Monitor Usage**: Check Serial Monitor for activity logs  
3. **Consider Upgrades**: RTC module, SD logging, WiFi connectivity
4. **Maintenance**: Periodically backup employee data
5. **Customization**: Modify LCD messages, add features

## Support Resources

- **Arduino Reference**: https://www.arduino.cc/reference/
- **MFRC522 Library**: Search "MFRC522" in Arduino Library Manager
- **Wiring Issues**: Check `wiring_guide.md` for detailed connections
- **Code Questions**: Review inline comments in main sketch file

---

**Important Safety Note**: Always verify connections before powering on. Use proper voltage levels (5V for NFC V3 and LCD shield, standard voltages for LEDs and buzzer).