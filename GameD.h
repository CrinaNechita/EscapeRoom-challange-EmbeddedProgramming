//Test your ear game
#ifndef GAMED_H
#define GAMED_H

#include <Arduino.h>
#include "Buzzer.h"
#include <ctime>
#include <cmath>
#include <cstdlib>
#define WIPER_PIN A0
#define DELAY_TIME 1000
#define BUZZER_PIN 8

extern Buzzer buzzer;

class GameD {
private:
  int randomNumber = 0;
  int gameDifficulty = 0;
  boolean shouldBreak = false;

  void increaseDifficulty();
  void checkForWin(int value);
public:
  GameD();
  void setup();
  void loop();
};



#endif