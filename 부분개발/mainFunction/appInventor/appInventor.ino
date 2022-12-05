#include <LiquidCrystal.h>

#define maxChar 32
char message[maxChar]; // stores the message
char readChar; // reads each character
byte index = 0; // defines the position into your array
int i;

LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  delay(1000);
}
void loop() {
  if (Serial.available()) {
    for (i = 0; i < 31; i++) {
      message[i] = '\0';
    }
    index = 0;
  }
  while (Serial.available() > 0) {
    //the message can have up to 100 characters
    if (index < (maxChar - 1)) {
      readChar = Serial.read(); // Reads a character
      message[index] = readChar; // Stores the character in message array
      index++; // Increment position
      message[index] = '\0'; // Delete the last position
    }
  }
  lcd.clear();
  lcd.print(message);
  for (int positionCounter = 0; positionCounter < i / 2; positionCounter++) {
    delay(750);
    lcd.scrollDisplayLeft();
  }
}
