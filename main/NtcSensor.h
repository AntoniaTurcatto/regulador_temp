#pragma once
#include <Arduino.h>

class NtcSensor {
public:
    NtcSensor(uint8_t pino, float rFixo, float r0, float t0, float beta, uint16_t adc_max);
    void begin();
    float getResist();
    float getKelvin();
    float getCelsius();

private:
    uint8_t _pino;
    uint16_t _adc_max;
    float _rFixo, _r0, _t0, _beta;
};