#include <LiquidCrystal_I2C.h>

int p1Button = 2;
int p2Button = 3;

LiquidCrystal_I2C lcd(0x27, 16, 2); // I2C address 0x27, 16 column and 2 rows

bool needsDisplayUpdate = true;
bool needsResetDelay = false;
int p1Score = 0;
int p2Score = 0;
int debounceDelay = 300; // debounce delay in ms
int resetDelay = 1000; // how long in ms until we accept score after clearing

void setup()
{
  lcd.init(); // initialize the lcd
  lcd.backlight();

  // Set pins 2 and 3 to input and enable the pull-up resistors
  pinMode(p1Button, INPUT_PULLUP);
  pinMode(p2Button, INPUT_PULLUP);
}

void loop()
{
  if (needsDisplayUpdate) {
    updateDisplay();
    needsDisplayUpdate = false;
    delay(debounceDelay); // Lazy debounce. Real engineers go to bed at a reasonable hour.
  }

  if (needsResetDelay) {
    delay(resetDelay);
    needsResetDelay = false;
  }

  int p1Read = digitalRead(p1Button);
  int p2Read = digitalRead(p2Button);

  // We check for when the pin is low instead of high because of weird pull-up 
  // resistor stuff.
  if (p1Read == LOW) {
    p1Score += 1;
    needsDisplayUpdate = true;
  }

  if (p2Read == LOW) {
    p2Score += 1;
    needsDisplayUpdate = true;
  }

  // Hold down both buttons to reset the screen.
  if ((p1Read == LOW) && (p2Read == LOW)) {
    p1Score = 0;
    p2Score = 0;
    needsDisplayUpdate = true;
    // Set reset delay to cause a delay after drawing so that we dont accidentally
    // accept input right after clearing.
    needsResetDelay = true; 
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
