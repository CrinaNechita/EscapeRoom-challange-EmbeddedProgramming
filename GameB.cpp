//Decoding secret numbers
#include "GameB.h"

GameB::GameB() {
}

void GameB::setup() {
  gameIncreasesDifficulty();  //goes to difficulty 1 and sets up difficulty variables
}

void GameB::loop(){
  while (!shouldBreak){
    uint8_t buttonStatus = tm.readButtons();

  bool anyButtonPressed = (buttonStatus != 0);

  if (anyButtonPressed) {
    handleButton(buttonStatus);
    delay(DELAY_TIME);
  }
  }

}

void GameB::gameIncreasesDifficulty() {
  gameDifficulty++;
  if (gameDifficulty > 3) {
    //go to next game
    Serial.println("Next game");
    shouldBreak = true;
  }
  //Generate a random number for the arrow on the second row
  srand(time(0));                
  int random = rand() % 10 + 1;  
  random = rand() % (gameDifficulty * 10) + 1;
  //Display the decimal number on the Whadda
  tm.displayIntNum(random, 0, TMAlignTextRight);
  Serial.println(random);

  //convert random number to binary
  convertToBinary(random);
}

void GameB::handleButton(uint8_t button) {
  //Log tells me which button was pressed (values vary from 0 to 7)
  int buttonId = (int)log2(button);
  //Light the LED
  tm.setLED(buttonId, 1);
  //Remember which led was lit
  buttonsPressed[buttonId] = 1;
  checkForWin();
}

void GameB::convertToBinary(int number) {
  for (int i = 7; i >= 0; i--) {
    binaryNumber[7 - i] = ((number >> i) & 1);
    Serial.print(binaryNumber[7 - i]);
  }
  Serial.println();
}

void GameB::clearTry() {
  //Clear array of buttons pressed
  for (int i = 0; i < 8; ++i) {
    buttonsPressed[i] = 0;
  }
  //Clear leds
  tm.setLEDs(0000000000000000);
}

bool GameB::areEqual(int binaryNumber1[], int binaryNumber2[]) {
  for (int i = 0; i < 8; i++) {
    if (binaryNumber1[i] != binaryNumber2[i]) {
      return false;  // If any element differs, arrays are not equal
    }
  }
  return true;  // All elements are equal, arrays are equal
}

bool GameB::didLose(int binaryNumber[], int buttonsPressed[]) {
  //Checkin if too many LEDs have been lit (quick way to determine loss)
  int sum1 = 0;
  int sum2 = 0;
  for (int i = 0; i < 8; i++) {
    sum1 += binaryNumber[i];
    sum2 += buttonsPressed[i];
    if (sum2 > sum1) {
      return true;  // Too many ones
    }
  }
  return false;
}

void GameB::checkForWin() {

  bool playerLost = didLose(binaryNumber, buttonsPressed);
  if (playerLost) {
    tm.displayText("try again");
    delay(3000);
    clearTry();
    //Give another chance
    gameDifficulty--;
    gameIncreasesDifficulty();
  } else {
    bool equal = areEqual(binaryNumber, buttonsPressed);
    if (equal) {
      tm.displayText("you won");
      Serial.print("You won!");
      delay(3000);
      clearTry();
      gameIncreasesDifficulty();
    }
  }
}










