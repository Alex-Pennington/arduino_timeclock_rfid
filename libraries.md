# Required Arduino Libraries

This project requires the following Arduino libraries to be installed:

## Core Libraries for Elechouse NFC V3 + HW-555 LCD Shield
- **NDEF** - NFC Data Exchange Format library
- **PN532** - PN532 NFC/RFID controller library
- **PN532_SPI** - SPI interface for PN532
- **LiquidCrystal_I2C** - I2C LCD display library for HW-555 shield
- **Wire** - I2C communication library (built-in)
- **SPI** - Serial Peripheral Interface library (built-in)
- **EEPROM** - EEPROM storage library (built-in)

## Installation Instructions

### Using PlatformIO (Recommended):
```bash
# All libraries install automatically when you build
pio run
```

### Using Arduino IDE Library Manager:
1. Open Arduino IDE
2. Go to Sketch > Include Library > Manage Libraries
3. Search for "NDEF" and install by Don Coleman
4. Search for "PN532" and install by Elechouse/Seeed Studio
5. Search for "LiquidCrystal I2C" and install by Frank de Brabander
6. The other libraries (Wire, SPI, EEPROM) are built-in

### Manual Installation:
If you prefer to install manually:
1. Download NDEF library from: https://github.com/don/NDEF
2. Download PN532 library from: https://github.com/elechouse/PN532
3. Extract both to your Arduino libraries folder
4. Restart Arduino IDE

## Library Versions
- NDEF: v0.2.0 or later
- PN532: v1.4.0 or later  
- LiquidCrystal_I2C: v1.1.2 or later
- Wire: Built-in Arduino library
- SPI: Built-in Arduino library  
- EEPROM: Built-in Arduino library