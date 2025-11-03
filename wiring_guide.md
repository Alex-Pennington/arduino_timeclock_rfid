# Arduino RFID Time Clock - Wiring Guide

## Complete Wiring Diagram

### Arduino Uno Pin Usage Summary - NFC V3 + HW-555 LCD Shield
```
Digital Pins:
Pin 2  -> Available for expansion
Pin 3  -> Available for expansion
Pin 4  -> Available for expansion
Pin 5  -> Available for expansion
Pin 6  -> Available for expansion
Pin 7  -> Green LED (+ 220Ω resistor)
Pin 8  -> Red LED (+ 220Ω resistor)
Pin 9  -> Buzzer (+)
Pin 10 -> NFC V3 SS
Pin 11 -> NFC V3 MOSI
Pin 12 -> NFC V3 MISO
Pin 13 -> NFC V3 SCK

Analog Pins:
A0 -> HW-555 LCD Shield buttons (analog input)
A1 -> Available for expansion
A2 -> Available for expansion
A3 -> Available for expansion
A4 -> I2C SDA (HW-555 LCD Shield)
A5 -> I2C SCL (HW-555 LCD Shield)

Power:
5V  -> HW-555 LCD Shield, NFC V3 VCC, LED anodes via resistors
GND -> All component grounds
```
Digital Pins:
Pin 2  -> LCD D7
Pin 3  -> LCD D6  
Pin 4  -> LCD D5
Pin 5  -> LCD D4
Pin 6  -> Red LED (+ 220Ω resistor)
Pin 7  -> Buzzer (+)
Pin 8  -> LCD Enable
Pin 9  -> LCD RS
Pin 10 -> NFC V3 SS
Pin 11 -> NFC V3 MOSI
Pin 12 -> NFC V3 MISO
Pin 13 -> NFC V3 SCK

Analog Pins:
A0 -> Button Shield (SELECT)
A1 -> Button Shield (LEFT)  
A2 -> Button Shield (UP)
A3 -> Button Shield (DOWN)
A4 -> Button Shield (RIGHT)
A5 -> (Available for expansion)

Analog Pins:
A0 -> Button Shield (SELECT)
A1 -> Button Shield (LEFT)  
A2 -> Button Shield (UP)
A3 -> Button Shield (DOWN)
A4 -> Button Shield (RIGHT)
A5 -> Green LED (+ 220Ω resistor)

Power:
5V  -> LCD VDD, Button Shield VCC, NFC V3 VCC, LED anodes via resistors
GND -> All component grounds
```

## Detailed Component Connections

### 1. Elechouse NFC V3 Module
```
NFC V3 Pin  | Arduino Pin | Wire Color (suggested)
------------|-------------|----------------------
VCC         | 5V          | Red
GND         | GND         | Black
SCL         | 13 (SCK)    | Orange
SDA         | 11 (MOSI)   | Green
MISO        | 12          | Blue
SCK         | 13          | Orange
SS          | 10          | Purple
RST         | Not used    | -
IRQ         | Not used    | -
```

**Important Notes:**
- Elechouse NFC V3 operates at 5V (unlike MFRC522)
- Uses SPI communication protocol
- IRQ and RST pins are not used in this project
- Keep wires short to avoid interference
- Module supports both NFC and RFID cards

### 2. HW-555 LCD Shield - I2C Connection
```
HW-555 Shield | Arduino Pin | Notes
--------------|-------------|---------------------------
VCC           | 5V          | Shield power supply
GND           | GND         | Ground connection
SDA           | A4          | I2C data line
SCL           | A5          | I2C clock line
Button Array  | A0          | Analog input for buttons
```

**HW-555 LCD Shield Features:**
- 16x2 LCD display with I2C interface (PCF8574 chip)
- Built-in 5-button keypad (Right, Up, Down, Left, Select)
- Adjustable contrast via onboard potentiometer
- Backlight control via I2C
- Stackable design - plugs directly onto Arduino Uno
- I2C address typically 0x27 (may vary by manufacturer)

### 3. HW-555 LCD Shield Buttons (Built-in)
```
Button | Analog Value | Tolerance Range
-------|--------------|----------------
RIGHT  | 0            | 0-50
UP     | 99           | 49-149
DOWN   | 256          | 206-306
LEFT   | 410          | 360-460
SELECT | 640          | 590-690
NONE   | 1023         | 900+
```

**HW-555 Button Operation:**
- All buttons read through single analog pin A0
- Uses voltage divider network on shield
- No external wiring required - built into shield
- Software debouncing implemented in code

### 4. LEDs and Buzzer - Updated for LCD Shield
```
Component   | Arduino Pin | Additional Components
------------|-------------|---------------------
Red LED     | Pin 8       | 220Ω resistor in series
Green LED   | Pin 7       | 220Ω resistor in series
Buzzer      | Pin 9       | Direct connection (active buzzer)
```

**LED Connections:**
- Anode (long leg) -> Resistor -> Arduino pin
- Cathode (short leg) -> GND

**Buzzer Connection:**
- Positive terminal -> Arduino pin 9
- Negative terminal -> GND

## Breadboard Layout Suggestions

### Power Rails
- Connect Arduino 5V to breadboard positive rail (for NFC V3 and external components)
- Connect Arduino GND to breadboard negative rail
- HW-555 LCD Shield gets power directly from Arduino headers

### Component Placement
1. **HW-555 LCD Shield**: Mounts directly on Arduino Uno (stackable design)
2. **NFC V3 Module**: Connect to breadboard or use jumper wires
3. **LEDs**: Breadboard with resistors
4. **Buzzer**: Breadboard or direct connection
5. **Minimal external wiring** required due to shield integration

### Wire Management Tips
- Use different colors for different voltage levels
- Keep power wires (red/black) separate from signal wires
- Use short, direct routes when possible
- Group related connections together

## Testing Connections

### Power Test
1. Connect only power and ground
2. Check voltages with multimeter:
   - 5V rail should measure 4.8-5.2V
   - 3.3V should measure 3.2-3.4V

### Component Tests
1. **LCD**: Should show backlight when powered
2. **MFRC522**: Blue LED should illuminate when powered
3. **LEDs**: Test with simple blink sketch
4. **Buzzer**: Test with tone() function
5. **Buttons**: Read analog values in serial monitor

### Signal Integrity
- Check all digital pins with multimeter
- Verify SPI connections with logic analyzer if available
- Test button analog readings

## Common Wiring Issues

### NFC V3 Problems
- **No card detection**: Check SPI wiring and 5V power
- **Intermittent operation**: Ensure short, solid connections
- **Communication errors**: Verify SS pin connection (pin 10)
- **Library errors**: Ensure NDEF and PN532 libraries are installed

### LCD Problems
- **No display**: Check power connections and contrast
- **Garbled text**: Verify data pin connections (D4-D7)
- **No backlight**: Check pins 14 and 15 connections

### Button Problems
- **No response**: Check analog pin connections
- **Wrong button readings**: Verify button shield type
- **Multiple buttons triggered**: Check for short circuits

## Safety Considerations

- Double-check all connections before powering on
- Use appropriate resistors for LEDs to prevent damage
- Ensure proper voltage levels (3.3V for MFRC522, 5V for others)
- Keep work area clean and organized
- Use proper gauge wire for current requirements

## Extension Options

### Future Expansion Pins
- Unused digital pins: Can be reconfigured if needed
- I2C pins (A4/A5): Note A5 is used for Green LED, A4 available for I2C
- Analog pins: A0-A4 used for buttons, consider I2C button expander

### Additional Modules
- **Real-time Clock (DS3231)**: Connect via I2C
- **SD Card Module**: For data logging
- **WiFi Module (ESP8266)**: For remote connectivity
- **Temperature Sensor**: Environmental monitoring