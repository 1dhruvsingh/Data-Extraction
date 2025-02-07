#include <LiquidCrystal_I2C.h>
#define I2C_ADDR 0x27
#define LCD_COLUMNS  20
#define LCD_LINES 4

LiquidCrystal_I2C(I2C_ADDR, LCD_COLUMNS, LCD_LINES);

void setup(){
  lcd.init();
  lcd.backlight();
  lcd.setCursor(3,0);
  lcd.print("Hello World!");
  lcd.setCursor(2,1);
  lcd.print("We are using IoT");
  lcd.setCursor(5,2);
  lcd.print("Simulator");
  lcd.setCursor(7,3);
  lcd.print("Enjoy!");
}

void loop(){

}
