# Library for MCP3208/3205

## Arduino library for MCP3208/3205

# Features

- Read single channel
- Set different SPI pins
- Works on AVR and RP2040 based boards (Arduino Uno, Nano, Mega, ... and Raspberry Pi Pico, RP2040)

# Usage

### Initialize MCP32:

``MCP3204_MCP3208 mcp(<channelCount>, <csPin>, <sckPin>, <mosiPin>, <misoPin>);``

- **channelCount**: number of analog channel
- **csPin**: chip select pin for SPI interface
- **sckPin**: set SCK pin for SPI interface (only on RP2040 based boards)
- **mosiPin**: set MOSI pin for SPI interface (only on RP2040 based boards)
- **misoPin**: set MISO pin for SPI interface (only on RP2040 based boards)

### Read analog channel

``mcp.readChannel(<channel>);``

- **channel**: number of channel that should be read e.g. ``0``

Return the analog value of the channel 0-4095

# Notes

- Tested on Raspberry Pi Pico and Arduino Uno
- Only tested with the 8 channel version (MCP3208) but should also work on all channel options
