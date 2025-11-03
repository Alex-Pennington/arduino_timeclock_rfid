# PlatformIO Project Configuration

This project has been configured for PlatformIO to enable automated library management and easier development workflow.

## Quick Start with PlatformIO

### 1. Install PlatformIO
```bash
# Install PlatformIO CLI
pip install platformio

# Or use VS Code extension
# Search for "PlatformIO IDE" in VS Code extensions
```

### 2. Build and Upload
```bash
# Navigate to project directory
cd arduino_timeclock_rfid

# Build the project (automatically installs libraries)
pio run

# Upload to Arduino Uno
pio run --target upload

# Open serial monitor
pio device monitor
```

### 3. Development Workflow
```bash
# Clean build files
pio run --target clean

# Check code for issues
pio check

# Run tests (if any)
pio test

# Update libraries
pio lib update
```

## Project Structure
```
arduino_timeclock_rfid/
├── platformio.ini      # PlatformIO configuration
├── src/
│   └── main.cpp       # Main Arduino sketch
├── include/
│   ├── config.h       # Pin definitions and constants
│   └── utils.h        # Utility functions
├── lib/               # Custom libraries (if any)
├── test/              # Unit tests
└── library.json       # Library metadata
```

## Automated Features

### Library Management
All required libraries are automatically installed:
- **PN532** (v1.2+) - NFC/RFID communication
- **LiquidCrystal_I2C** (v1.1.2+) - I2C LCD control
- **NDEF** (v0.2+) - NFC data format support

### Build Configuration
- Target: Arduino Uno
- Framework: Arduino
- Serial Monitor: 9600 baud with colorization
- Optimization: Size-optimized (-Os)
- Code checking: cppcheck enabled

### Development Tools
- **Code Checking**: Automatic static analysis
- **Serial Monitor**: Built-in with filtering
- **Debug Support**: SimAVR integration
- **Upload Speed**: Optimized at 115200 baud

## VS Code Integration

### Recommended Extensions
- **PlatformIO IDE**: Complete development environment
- **C/C++**: IntelliSense and debugging
- **Serial Monitor**: Built-in terminal support

### Features
- Automatic library installation
- IntelliSense code completion
- Integrated debugging
- Built-in serial monitor
- One-click build and upload

## Commands Reference

### Build Commands
```bash
pio run                    # Build project
pio run -e uno            # Build for specific environment
pio run --target upload   # Build and upload
pio run --target clean    # Clean build files
```

### Library Commands
```bash
pio lib search <name>     # Search for library
pio lib install <name>    # Install library
pio lib list             # List installed libraries
pio lib update           # Update all libraries
```

### Device Commands
```bash
pio device list          # List connected devices
pio device monitor       # Open serial monitor
pio device monitor -b 9600  # Monitor at specific baud rate
```

### Advanced Commands
```bash
pio check                # Run static code analysis
pio test                 # Run unit tests
pio debug               # Start debugging session
pio remote              # Remote development
```

## Configuration Options

The `platformio.ini` file contains all project settings:
- Target board and platform
- Library dependencies
- Build flags and options
- Upload and monitor settings
- Debug configuration

## Benefits of PlatformIO

1. **Automated Setup**: No manual library installation
2. **Better IntelliSense**: Accurate code completion
3. **Dependency Management**: Automatic library updates
4. **Multi-Platform**: Works on Windows, Mac, Linux
5. **Advanced Features**: Debugging, testing, remote development
6. **IDE Integration**: Works with VS Code, CLion, etc.

## Migration from Arduino IDE

Your existing Arduino sketch works without changes:
- `*.ino` files are automatically recognized
- All Arduino functions and libraries work
- Serial Monitor and upload work the same way
- Existing libraries can be imported

## Troubleshooting

### Common Issues
1. **Library not found**: Check `platformio.ini` lib_deps
2. **Upload failed**: Check board and port selection
3. **Build errors**: Verify include paths and dependencies

### Reset Configuration
```bash
pio system prune        # Clean system cache
rm -rf .pio             # Remove build cache
pio run                 # Rebuild project
```