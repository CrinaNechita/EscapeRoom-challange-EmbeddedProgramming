//Test your ear game
#include "GameD.h"

GameD::GameD() {
}

void GameD::setup() {
  srand(time(0));
  pinMode(WIPER_PIN, INPUT);
  increaseDifficulty();
}

void GameD::loop() {
  while (!shouldBreak){
    int value = analogRead(WIPER_PIN);
  Serial.printf("%d -->%d mV/n", value,
                map(value, 0, 1023, 0, 3300));
  tone(BUZZER_PIN, value, 900);
  delay(1000);
  Serial.println();
  checkForWin(value);
  }
  
  
}


void GameD::checkForWin(int value) {
  //Checks if value is equal to the solution or in its range
  if (abs(value - randomNumber) <= 10 || value == randomNumber) {
    Serial.println("You won");
    delay(2000);
    increaseDifficulty();
  }
}

void GameD::increaseDifficulty(){
  delay(3000);
  gameDifficulty++;
  if(gameDifficulty > 3){
    Serial.println("You won everything!");
    delay(2000);
    shouldBreak = true;
  }
  //Generate a random number in the range 20 - 1020
  int randomFrequency = rand() % (333 * gameDifficulty) + 20;
  //randomFrequency = rand() % (340 * gameDifficulty) + 1;
  randomNumber = randomFrequency;
  Serial.printf("random: %d\n", randomNumber);
  tone(BUZZER_PIN, randomNumber, 500);
  delay(1500);
}
