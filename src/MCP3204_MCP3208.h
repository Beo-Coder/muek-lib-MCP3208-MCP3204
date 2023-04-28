

// Copyright (c) 2023. Leonhard Baschang

#ifndef MCP3208_LIB_MCP3204_MCP3208_H
#define MCP3208_LIB_MCP3204_MCP3208_H
#include "SPI.h"

class MCP3204_MCP3208 {
#if defined(ARDUINO_RASPBERRY_PI_PICO)
    MbedSPI *spi;
#else
    SPIClass *spi;
#endif


    uint8_t csPin;
    uint8_t channelCount;
public:

    MCP3204_MCP3208(uint8_t channelCount, uint8_t csPin, uint8_t sckPin = PIN_SPI_SCK, uint8_t mosiPin = PIN_SPI_MOSI, uint8_t misoPin = PIN_SPI_MISO);

    uint16_t readChannel(uint8_t channel);


};


#endif //MCP3208_LIB_MCP3204_MCP3208_H
