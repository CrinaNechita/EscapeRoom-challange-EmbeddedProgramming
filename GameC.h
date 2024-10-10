//Minimalistic piano
#ifndef GAMEC_H
#define GAMEC_H

#include <TM1638plus.h>
#include <Arduino.h>
#include "Buzzer.h"
#define DELAY_TIME 100
#define BUZZER_PIN 8

extern Buzzer buzzer;
extern TM1638plus tm;


class GameC {
public:
  GameC();
  void setup();
  void loop();

private:

  int playerDuration = 0;
  int playerNotes[30];
  int playerDurations[30];
  int position = 0;
  int frequency = 0;
  boolean shouldBreak = false;

  void sing();
  void handleButton(uint8_t button);
  void checkForWin();
  void startOver();
  void storeNotesSung();
  void debugger();

  // Flexible array members need to be declared at the end?
  int frequences[13];
  int durations[13];
};



#endif