#include "LCDDisplay.h"

LCDDisplay::LCDDisplay(uint8_t port0, uint8_t port1, uint8_t port2, uint8_t port3,
                       uint8_t port4, uint8_t port5, uint8_t port6, uint8_t port7,
                       uint8_t portEnable, uint8_t portRW, uint8_t portRS)
  : _port0(port0), _port1(port1), _port2(port2), _port3(port3),
    _port4(port4), _port5(port5), _port6(port6), _port7(port7),
    _portEnable(portEnable), _portRW(portRW), _portRS(portRS) { }

void LCDDisplay::begin()
{

}