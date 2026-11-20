#include "NtcSensor.h"

NtcSensor::NtcSensor(uint8_t pino, float rFixo, float r0, float t0, float beta, uint16_t adc_max)
    : _pino(pino), _rFixo(rFixo), _r0(r0), _t0(t0), _beta(beta), _adc_max(adc_max) {}

void NtcSensor::begin() 
{
    pinMode(_pino, INPUT);
}

float NtcSensor::getResist() {
    // i = U/R
    // i = U2/R2
    
    // Req = R1 + R2
    // Req = U/i
    // Req =  U/(U2/R2)
    // Req =  R2.U/U2
    
    //R1 = Req - R2
    //R1 = R2.U/U2 - R2
    //R1 = R2(U/U2 - 1)
    //R1 = R2(adc_max/leitura - 1)


    int leitura = analogRead(_pino);
    if (leitura <= 0) leitura = 1;            
    return _rFixo * (float(_adc_max) / leitura - 1.0);
}

float NtcSensor::getKelvin() 
{
  // 1/T = 1/T0 + (1/β) . ln(R/R0)
  // 1 = T(1/T0) + T . (1/β) . ln(R/R0)
  // 1 = T((1/T0) + (1/β) . ln(R/R0))
  // T((1/T0) + (1/β) . ln(R/R0)) = 1
  // T = 1 / ((1/T0) + (1/β) . ln(R/R0))
  float r = getResist();
  return 1 / ((1/_t0) + (1/_beta) * log(r/_r0));
}

float NtcSensor::getCelsius() 
{
    return getKelvin() - 273.15;
}