// Copyright (c) 2023. Leonhard Baschang

#include <Arduino.h>
#include "MCP3204_MCP3208.h"


// Chip with 8 analog channel and pin 5 ist chip select
MCP3204_MCP3208 mcp(8, 5);


void setup() {
    Serial.begin(9600);

}


void loop() {

    // Reads all the 8 channel and print their values to the serial monitor
    Serial.println(mcp.readChannel(0));
    Serial.println(mcp.readChannel(1));
    Serial.println(mcp.readChannel(2));
    Serial.println(mcp.readChannel(3));
    Serial.println(mcp.readChannel(4));
    Serial.println(mcp.readChannel(5));
    Serial.println(mcp.readChannel(6));
    Serial.println(mcp.readChannel(7));

    Serial.println("-------------------------------------------------------------");
    delay(500);
}

