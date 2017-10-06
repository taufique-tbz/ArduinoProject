#include <LiquidCrystal.h>         

LiquidCrystal lcd(7, 6, 5, 4, 3, 2); 
const int inPin = 0;                   

void setup()
{
  lcd.begin(16,2);
}

void loop()
{
  int value = analogRead(inPin); 
  float millivolts = (value / 1024.0) * 5000; 
  float celsius = millivolts / 10;
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Celsius: ");
  lcd.print(celsius);
  lcd.print("C");
  lcd.setCursor(0,1);
  lcd.print("Fahrenh: ");
  lcd.print((celsius * 9)/5 + 32); 
  lcd.print("F");
  delay(5000);
}
