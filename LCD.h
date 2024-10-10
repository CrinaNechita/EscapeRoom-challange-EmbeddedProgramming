#ifndef BUZZER_H
#define BUZZER_H
#define LCD_COLS 16
#define LCD_ROWS 2

#include <Arduino.h>
#include <LiquidCrystal_I2C.h>

class LCD {
private:
  uint8_t lcd_cols;
  uint8_t lcd_rows;
  LiquidCrystal_I2C lcd;

public:
  LCD();
  LCD(int lcd_cols, int lcd_rows); 
  void setUp();
  void setCursor(int cursor, int row);
  void write(int code);
  void print();
  void clear();
};

#endif
//LiquidCrystal_I2C lcd(0x27, LCD_COLS, LCD_ROWS);