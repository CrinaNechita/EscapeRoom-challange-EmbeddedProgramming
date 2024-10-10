#include "Buzzer.h"
#include "GameA.h"
#include "GameB.h"
#include "GameC.h"
#include "GameD.h"
#include <TM1638plus.h>
#include <LiquidCrystal_I2C.h>

#define BUZZER_PIN 8
Buzzer buzzer(BUZZER_PIN);
#define LCD_COLS 16
#define LCD_ROWS 2
LiquidCrystal_I2C lcd(0x27, LCD_COLS, LCD_ROWS);
#define TM_STROBE 4
#define TM_CLOCK 6
#define TM_DIO 7
TM1638plus tm(TM_STROBE, TM_CLOCK, TM_DIO);
#define INTERVAL 600
HardwareTimer timer(TIM2);
unsigned long startTime; 
unsigned long elapsedTime;

GameA gameA;
GameB gameB;
GameC gameC;
GameD gameD;

void setup() {
  tm.displayBegin();
  Serial.begin(115200);

  gameA.setup();
  delay(2000);

  uint32_t clockFreq = timer.getTimerClkFreq();
  timer.setPrescaleFactor(12000);
  uint32_t prescaler = timer.getPrescaleFactor();
  timer.setOverflow(clockFreq / prescaler * INTERVAL);
  timer.attachInterrupt(timerInterrupt);
  timer.resume();

  startTime = millis();
  gameA.loop();
  lcd.clear();
  displayTimeLeft();
  gameB.setup();
  delay(2000);
  gameB.loop();
  displayTimeLeft();
  gameC.setup();
  delay(2000);
  gameC.loop();
  displayTimeLeft();
  gameD.setup();
  delay(2000);
  gameD.loop();
  displayTimeLeft();
  lcd.print("you won");
}

void loop() {
}


void timerInterrupt() {
  lcd.setCursor(0, 0);
  lcd.print("you lost");
  delay(10000);
}

void displayTimeLeft(){
  lcd.setCursor(0, 1);
  elapsedTime = millis() - startTime;
  lcd.print(elapsedTime);
}
