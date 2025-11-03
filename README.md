# Arduino NFC Time Clock System

A comprehensive NFC/RFID-based employee time tracking system using Arduino Uno with LCD display and button controls.

## Features

- **NFC/RFID Employee Cards**: Quick clock in/out with NFC card scanning using Elechouse NFC V3
- **LCD Display**: Real-time feedback and menu navigation on HW-555 LCD
- **Button Controls**: Full admin menu system with button shield
- **Employee Management**: Add, view, and manage up to 10 employees
- **Data Storage**: Persistent storage using Arduino EEPROM
- **Visual/Audio Feedback**: LED indicators and buzzer for user feedback
- **Admin Interface**: Complete administrative controls via button navigation

## Hardware Requirements

### Components
- Arduino Uno R3
- Elechouse NFC V3 Module (PN532-based)
- HW-555 LCD Shield (16x2 I2C display with built-in buttons)
- LEDs (Red and Green) with 220Ω resistors
- Buzzer (active type)
- NFC Cards/Tags or RFID Cards
- Minimal jumper wires (LCD shield reduces wiring complexity)

### Wiring Diagram

#### MFRC522 RFID Module
```
MFRC522    Arduino Uno
VCC     -> 3.3V
RST     -> Pin 9
GND     -> GND
IRQ     -> Not connected
MISO    -> Pin 12
MOSI    -> Pin 11
SCK     -> Pin 13
SDA     -> Pin 10
```

#### HW-555 LCD Display
```
LCD Pin    Arduino Uno
VSS     -> GND
VDD     -> 5V
V0      -> Middle pin of 10kΩ potentiometer
RS      -> Pin 12
Enable  -> Pin 11
D4      -> Pin 5
D5      -> Pin 4
D6      -> Pin 3
D7      -> Pin 2
A       -> 5V (backlight)
K       -> GND (backlight)
```

#### Button Shield (Analog)
```
Button     Arduino Pin
Select  -> A0
Left    -> A1
Up      -> A2
Down    -> A3
Right   -> A4
```

#### LEDs and Buzzer
```
Component    Arduino Pin
Red LED   -> Pin 7
Green LED -> Pin 6
Buzzer    -> Pin 8
```

## Software Requirements

### Arduino Libraries
Install these libraries through the Arduino IDE Library Manager:
- **NDEF** (by Don Coleman)
- **PN532** (by Elechouse/Seeed Studio)
- **LiquidCrystal_I2C** (by Frank de Brabander)
- **Wire** (built-in)
- **SPI** (built-in)
- **EEPROM** (built-in)

### Development Environment
- **PlatformIO** (Recommended) - Automated library management
- Arduino IDE 1.8.19 or later
- VS Code with PlatformIO IDE extension

## Installation

### Option 1: PlatformIO (Recommended)
```bash
# Clone or download project
# Open in VS Code with PlatformIO extension

# Build and upload (libraries install automatically)
pio run --target upload

# Open serial monitor
pio device monitor
```

### Option 2: Arduino IDE
1. **Hardware Setup**:
   - Connect all components according to the wiring diagram
   - Double-check all connections

2. **Software Setup**:
   - Install required libraries manually
   - Upload the `src/main.cpp` sketch to Arduino Uno
   - Open Serial Monitor (9600 baud) for debugging

3. **System Configuration**:
   - Power on the system
   - Use admin menu to add employees
   - Test RFID cards and button navigation

## Usage

### Basic Operation
1. **Clock In/Out**: Simply scan your NFC/RFID card near the reader
2. **Admin Access**: Press SELECT button to enter admin menu
3. **Navigation**: Use UP/DOWN to navigate, SELECT to confirm, LEFT to go back

### Admin Functions
- **Add Employee**: Register new RFID cards with employee names
- **View Employees**: Browse registered employees
- **Clock History**: View recent clock in/out events
- **System Settings**: Configure system parameters

### Employee Management
1. Enter admin menu (SELECT button)
2. Choose "Add Employee"
3. Scan new RFID card
4. Enter employee name using button navigation
5. Confirm to save

## System States

### Main Screen
- Displays "RFID Time Clock"
- Shows "Scan Card/Press" prompt
- Green LED indicates system ready

### Clock In/Out Feedback
- **Clock In**: Green LED flash, high beep, "Clocked In" message
- **Clock Out**: Red LED flash, low beep, "Clocked Out" message
- **Unknown Card**: Red LED, error beep, "Access Denied" message

## Data Storage

The system uses Arduino EEPROM for persistent storage:
- Employee data (UID, name, timestamps)
- Clock in/out history
- System configuration
- Data survives power cycles

## Troubleshooting

### Common Issues
1. **NFC not reading**: Check SPI connections, ensure 5V power to NFC V3
2. **LCD not displaying**: Verify connections, adjust contrast potentiometer
3. **Buttons not responding**: Check analog pin connections and pull-up resistors
4. **Data not saving**: Verify EEPROM operations, check for memory corruption
5. **Library errors**: Ensure NDEF and PN532 libraries are properly installed

### Debug Mode
Enable Serial Monitor (9600 baud) to view:
- NFC/RFID card UIDs
- Employee clock events
- System status messages
- Error diagnostics

## Technical Specifications

- **Power Requirements**: 5V DC via USB or barrel jack
- **Memory Usage**: ~50% of Arduino Uno flash memory
- **Employee Capacity**: 10 employees maximum
- **EEPROM Storage**: 1KB for employee data
- **Response Time**: <500ms for RFID scanning
- **Operating Range**: RFID range ~3cm

## Future Enhancements

- Real-time clock module (DS3231) for accurate timestamps
- SD card logging for extended history
- WiFi connectivity for remote monitoring
- Battery backup for power outages
- Expanded employee capacity with external EEPROM

## License

This project is open source and available under the MIT License.

## Support

For issues and questions:
1. Check the troubleshooting section
2. Review wiring connections
3. Verify library installations
4. Check Serial Monitor for debug information