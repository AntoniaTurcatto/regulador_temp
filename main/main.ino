#include "NtcSensor.h"

NtcSensor ntc(A0, 10000.0, 10000.0, 298.15, 3950.0, 1023); 

// ---- Relé ------
const uint8_t PINO_RELE = 11;

void setup() {
    Serial.begin(9600);
    ntc.begin();
    configurarRele();
}

void configurarRele() {
    digitalWrite(PINO_RELE, HIGH); // Relé começa desligado
    pinMode(PINO_RELE, OUTPUT);
}

void ativarRele(bool ligar) {
    digitalWrite(PINO_RELE, ligar ? LOW : HIGH); //liga em LOW, desliga em HIGH  
} 

void loop() {
   float celsius = ntc.getCelsius();
   Serial.println(celsius);
   delay(1000);
}