#include <LiquidCrystal.h>

#define maxChar 32
char message[maxChar]; // stores the message
char readChar; // reads each character
byte index = 0; // defines the position into your array
int i, n=0;

const unsigned int LED = 6; // 6번 핀 LCD의 밝기 조절
const int analogPin = A0;   // 조도센서의 값 읽음

LiquidCrystal lcd(7,8,9,10,11,12);


void setup() {
  pinMode(LED, OUTPUT);
  pinMode(13, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  }

void loop() {
  int a = analogRead(analogPin)/3;  // 0~1024의 값을 0~255의 값으로 맞춤
  if (a>255)  a = 255;    // 255가 넘으면 밝기가 달라지므로 255로 맞춤
  analogWrite(LED, a);    // 밝기 출력


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
