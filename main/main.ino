#include "NtcSensor.h"

NtcSensor ntc(A0, 10000.0, 10000.0, 298.15, 3950.0, 1023);   // usa os valores padrão: 10k, 10k, B=3950

void setup() {
    Serial.begin(9600);
    ntc.begin();
}

void loop() {
   float celsius = ntc.getCelsius();
   Serial.println(celsius);
   delay(1000);
}