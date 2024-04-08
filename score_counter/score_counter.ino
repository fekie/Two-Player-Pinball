#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows
bool needsDisplayUpdate = true;
int p1Score = 0;
int p2Score = 0;

void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();

  // Set pins 2 and 3 to input and enable the pull-up resistors
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);

  // board debug led
  pinMode(13, OUTPUT);

  
}

void loop()
{
  if (needsDisplayUpdate) {
    updateDisplay();
    needsDisplayUpdate = false;
  }

  
}

void updateDisplay()
{
  lcd.clear();
  lcd.setCursor(0, 0);         
  lcd.print("P1 Score: ");        
  lcd.print(p1Score);
  lcd.setCursor(0, 1);        
  lcd.print("P2 Score: ");
  lcd.print(p2Score); 
}
