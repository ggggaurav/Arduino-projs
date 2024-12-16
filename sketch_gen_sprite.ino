
#include <LiquidCrystal.h>

// LCD pin mapping for Duinotech shield: 
// RS → D8, E → D9, D4 → D4, D5 → D5, D6 → D6, D7 → D7
LiquidCrystal lcd(8, 9, 4, 5, 6, 7);





void initializeGraphics(){
  static byte graphics[] = {
    // Run position 1
    B01100,
    B01100,
    B00000,
    B01110,
    B11100,
    B01100,
    B11010,
    B10011,
  };



  // Load the character into CGRAM at index 0
  lcd.createChar(0, graphics);

}
void setup() {
  // Initialize the LCD with the given number of columns and rows
  lcd.begin(16, 2);

  // Set up the custom character patterns
  initializeGraphics();

  // Move the LCD cursor to column 0, row 0
  lcd.setCursor(0, 0);

  // Write the custom character (stored at index 0) to the screen
  lcd.write((byte)0);
}

void loop() {
  // Nothing needed here; the character remains displayed
}
