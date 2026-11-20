#pragma once
#include <Arduino.h>

class LCDDisplay {
public:
    LCDDisplay(uint8_t port0, uint8_t port1, uint8_t port2, uint8_t port3,
               uint8_t port4, uint8_t port5, uint8_t port6, uint8_t port7,
               uint8_t portEnable, uint8_t portRW, uint8_t portRS);
    void begin();

private:
    uint8_t _port0, _port1, _port2, _port3, _port4, _port5, _port6, _port7;
    uint8_t _portEnable, _portRW, _portRS;
};