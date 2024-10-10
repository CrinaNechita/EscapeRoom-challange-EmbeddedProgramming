#include "LCD.h"

LCD::LCD() : lcd_cols(16), lcd_rows(2), lcd(0x27, 16, 2) {
}

LCD::LCD(int lcd_cols, int lcd_rows) : lcd_cols(lcd_cols), lcd_rows(lcd_rows), lcd(0x27, lcd_cols, lcd_rows) {
}


void LCD::setUp() {
  Serial.print("LCD set up");
  lcd.init();
  lcd.backlight();
  lcd.clear();
}

void LCD::setCursor(int cursor, int row) {
  lcd.setCursor(cursor, row);
}

void LCD::write(int code) {
  lcd.write(code);
}

void LCD::clear() {
  lcd.clear();
}

void LCD::print() {
  lcd.print("You won!");
}
