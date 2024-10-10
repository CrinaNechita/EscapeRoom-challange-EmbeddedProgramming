//Decoding secret numbers
#ifndef GAMEB_H
#define GAMEB_H

#include <TM1638plus.h>
#include <bitset>
#include <cstdlib>
#include <ctime>
#include <cmath>
#define DELAY_TIME 500

extern TM1638plus tm;


class GameB {
private:
  int decimalNumber = 0;
  int gameDifficulty = 0;
  int binaryNumber[8];
  int buttonsPressed[8];
  int i = 0;
  boolean shouldBreak = false;

  void gameIncreasesDifficulty();
  void handleButton(uint8_t button);
  void checkForWin();
  void convertToBinary(int number);
  void clearTry();
  bool areEqual(int binaryNumber1[], int binaryNumber2[]);
  bool didLose(int binaryNumber[], int buttonsPressed[]);

public:
  GameB();
  void setup();
  void loop();
};


#endif
