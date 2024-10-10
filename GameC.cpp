//Minimalistic piano
#include "GameC.h"

GameC::GameC() {
  //Sol (G note) ~ 392 Hz  - button S1
  //Mi (E note) ~ 330 Hz   - button S4
  int initFrequences[] = { 392, 330, 392, 392, 330, 392, 392, 330, 330, 392, 392, 330 };
  int initDurations[] = { 500, 500, 250, 250, 500, 250, 250, 250, 250, 250, 250, 500 };

  // Copy the initialized arrays to the flexible array members
  for (int i = 0; i < sizeof(initFrequences) / sizeof(initFrequences[0]); ++i) {
        frequences[i] = initFrequences[i];
        durations[i] = initDurations[i];
    }
}

void GameC::setup() {
  tm.reset();
  sing();
  delay(1500);
}

void GameC::loop() {
  while (!shouldBreak) {
    uint8_t buttonStatus = tm.readButtons();

    bool anyButtonPressed = (buttonStatus != 0);

    if (anyButtonPressed) {
      handleButton(buttonStatus);
    }
    if (!anyButtonPressed) {
      storeNotesSung();
      playerDuration = 0;
      delay(DELAY_TIME);
    }
  }
}

void GameC::sing() {
  for (int i = 0; i < 12; i++) {
    tone(BUZZER_PIN, frequences[i], durations[i]);
    delay(durations[i]);
    noTone(BUZZER_PIN);
    delay(50);
  }
}


void GameC::handleButton(uint8_t button) {
  //Log tells me which button was pressed (values vary from 0 to 7)
  int buttonId = (int)log2(button);
  Serial.println(buttonId);

  switch (buttonId) {
    case 0:
      frequency = 392;
      tone(BUZZER_PIN, frequency, DELAY_TIME);  //G note
      break;
    case 2:
      frequency = 330;
      tone(BUZZER_PIN, frequency, DELAY_TIME);  //E note
      break;
    case 6:
      startOver();
      break;
    case 7:
      sing();
      break;
    default:
      debugger();
  }

  playerDuration += DELAY_TIME;
  delay(DELAY_TIME);
}


void GameC::storeNotesSung() {
  //Store note played and duration
  if (playerDuration > 480) {
    playerDurations[position] = 500;
    playerNotes[position] = frequency;
    position++;

  } else {
    if (playerDuration > 190) {
      playerNotes[position] = frequency;
      playerDurations[position] = 250;
      position++;
    }
  }

  //If enough notes are played, we check if the song was right
  if (playerNotes[11] != 0) {
    checkForWin();
  }
}


void GameC::startOver() {
  for (int i = 0; i <= 29; i++) {
    playerDurations[i] = 0;
    playerNotes[i] = 0;
  }
  position = 0;
  Serial.println("wiped");
  tm.displayText("wiped");
  delay(1000);
  tm.displayText("         ");
}


void GameC::checkForWin() {
  boolean won = true;
  for (int i = 0; i < 12; i++) {
    if ((playerNotes[i] != frequences[i]) || (playerDurations[i] != durations[i])) {
      won = false;
    }
  }
  if (won) {
    Serial.println("Next game");
    debugger();
    tm.displayText("you won");
    shouldBreak = true; 
  } else {
    tm.displayText("try again");
    delay(1000);
    startOver();
  }
}



void GameC::debugger() {
  Serial.print("notes: ");
  for (int i = 0; i < 30; i++) {
    Serial.print(playerNotes[i]);
    Serial.print(" ");
  }
  Serial.println();
  Serial.print("durations: ");
  for (int i = 0; i < 30; i++) {
    Serial.print(playerDurations[i]);
    Serial.print(" ");
  }
  Serial.println();
}
