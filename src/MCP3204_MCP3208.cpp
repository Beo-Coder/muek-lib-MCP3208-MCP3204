

// Copyright (c) 2023. Leonhard Baschang

#include "Arduino.h"
#include "SPI.h"
#include "MCP3204_MCP3208.h"

MCP3204_MCP3208::MCP3204_MCP3208(uint8_t channelCount, uint8_t csPin) {
    this->channelCount = channelCount;
    this->csPin = csPin;
    pinMode(csPin, OUTPUT);
    digitalWrite(csPin, HIGH);
#if defined(ARDUINO_RASPBERRY_PI_PICO)
    spi = new MbedSPI(PIN_SPI_MISO, PIN_SPI_MOSI, PIN_SPI_SCK);
#else
    spi = new SPIClass();
#endif

    spi->begin();

}

MCP3204_MCP3208::MCP3204_MCP3208(uint8_t channelCount, uint8_t csPin, uint8_t sckPin, uint8_t mosiPin,
                                 uint8_t misoPin) {
    this->channelCount = channelCount;
    this->csPin = csPin;
    pinMode(csPin, OUTPUT);
    digitalWrite(csPin, HIGH);
#if defined(ARDUINO_RASPBERRY_PI_PICO)
    spi = new MbedSPI(misoPin, mosiPin, sckPin);
#else
    spi = new SPIClass();
#endif


    spi->begin();

}

uint16_t MCP3204_MCP3208::readChannel(uint8_t channel) {
    if (channel >= channelCount) {
        return 0;
    }
    uint8_t writeData[3];
    writeData[0] = 0b0000011 << 1 | ((channel & 0x04) >> 2);
    writeData[1] = ((channel & 0x02) << 6) | ((channel & 0x01) << 6) | 0x00;
    writeData[2] = 0x00;

    uint8_t outputData[2];

    digitalWrite(csPin, LOW);
    spi->transfer(writeData[0]);
    outputData[0] = spi->transfer(writeData[1]);
    outputData[1] = spi->transfer(writeData[2]);
    digitalWrite(csPin, HIGH);


    uint16_t data = (outputData[0] & 0b0001111) << 8 | outputData[1];

    return data;
}


