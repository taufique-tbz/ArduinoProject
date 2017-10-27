#include <LiquidCrystal.h>         

LiquidCrystal lcd(12, 11, 5, 4, 3, 2); //Digital pins to which you connect the LCD
                 // A0 is where you connect the sensor
void setup()
{
  lcd.begin(20,4);
}
void loop()
{

  lcd.setCursor(0,0);
  lcd.print("Moo");
  
  lcd.setCursor(0,1);
  lcd.print("Mein ");
  
  lcd.setCursor(0,2);
  lcd.print("Lega?");
  
  lcd.setCursor(0,3);
  lcd.print("Hain Karwaye...");
  
}
