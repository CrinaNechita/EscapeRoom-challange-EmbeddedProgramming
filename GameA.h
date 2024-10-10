//Catch the square
#ifndef GAMEA_H
#define GAMEA_H

#include <Arduino.h>
#include <cstdlib>
#include <ctime>
#include <LiquidCrystal_I2C.h>

extern LiquidCrystal_I2C lcd;

class GameA {
private:
  int waitTime = 100;
  int cursor = 1;
  int forward = 1;
  int gameDifficulty = 0;
  int pace = 100;
  int arrowPosition = 0;
  boolean shouldBreak = false;
  void checkForWin();
  void gameIncreasesDifficulty();
  void handleLCDDisplay();
public:
  GameA();
  void setup();
  void loop();
};

#endif