#ifndef BUZZER_H
#define BUZZER_H

#include <Arduino.h>

class Buzzer {
  private:
    uint8_t pin;

  public:
    Buzzer(uint8_t pin);

    void play(uint16_t frequency, uint32_t duration);
};

#endif