#include "Buzzer.h"

Buzzer::Buzzer(uint8_t pin) 
: pin(pin) {
  pinMode(pin, OUTPUT);
}

void Buzzer::play(uint16_t frequency, uint32_t duration) {
  Serial.printf("Buzzer is playing %d Hz, during %d ms at pin %d\n", 
    frequency, duration, pin);
  tone(pin, frequency, duration);
}