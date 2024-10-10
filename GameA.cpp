//Catch the square
#include "GameA.h"

GameA::GameA() {
}

void GameA::setup() {
  pinMode(USER_BTN, INPUT_PULLUP);
  lcd.init();
  lcd.backlight();
  lcd.clear();
  gameIncreasesDifficulty();  //goes to difficulty 1 and sets up difficulty variables
}

void GameA::loop() {
  while (!shouldBreak) {
    handleLCDDisplay();
    checkForWin();
  }
}

void GameA::gameIncreasesDifficulty() {
  gameDifficulty++;
  if (gameDifficulty > 3) {
    //go to next game
    Serial.print("Next game");
    shouldBreak = true;
  }
  //Increase the pace of the game
  pace = pace - 20;  //(by decreasing the time it takes the square to move, making it faster)
  //Generate a random number for the arrow on the second row
  srand(time(0));
  int random = rand() % 15 + 1;
  arrowPosition = random;
  //Draw the arrow on the LCD
  lcd.clear();
  lcd.setCursor(arrowPosition, 1);
  lcd.write(94);
  //Set cursor at the beginning for drawing the square
  lcd.setCursor(0, 0);
  lcd.write(255);
}

void GameA::handleLCDDisplay() {
  unsigned long currentMillis = millis();
  if (currentMillis > waitTime) {
    waitTime = waitTime + pace;
    //If the square is moving forward, we clear the square we drawn at position - 1 and then draw the next one
    if (forward == 1) {
      lcd.setCursor(cursor - 1, 0);
      lcd.write(32);  //blank character deletes square
      cursor++;
      lcd.write(255);  //square code
    }
    //If the square is moving backwards, we clear the square and move the cursor to the left to draw the next square
    else {
      lcd.setCursor(cursor, 0);
      lcd.write(32);  //blank
      cursor--;

      lcd.setCursor(cursor, 0);
      lcd.write(255);  //square
    }
  }
  //If the cursor reached the begining of the line, we start moving fowards
  if (cursor < 1) {
    forward = 1;
  }
  //If the cursor reached the end of the line, we start moving backwards
  if (cursor > 15) {
    forward = 0;
  }
}

void GameA::checkForWin() {
  int read = digitalRead(USER_BTN);
  if (read == LOW) {
    delay(5);
    Serial.println("You pressed the button at position:");
    Serial.println(cursor);
    delay(1000);

    //Checks that the player pressed the button with the square above the arrow
    if ((forward == 0 && cursor == arrowPosition) || (forward == 1 && cursor == arrowPosition + 1)) {
      gameIncreasesDifficulty();
      lcd.print("You won");
      delay(3000);
    }
  }
}
