#include <LiquidCrystal.h>

#define maxChar 32
char message[maxChar]; // stores the message
char readChar; // reads each character
byte index = 0; // defines the position into your array
int i;

const unsigned int LED = 3; // 3번 핀 LCD의 밝기 조절
const int analogPin = A0;   // 조도센서의 값 읽음


LiquidCrystal lcd(7,8,9,10,11,12);

void setup() {

  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.clear();
  delay(1000);
  pinMode(LED, OUTPUT);



  lcd.setCursor(0,0);
  lcd.print("Hello!");
  lcd.setCursor(0,1);
  lcd.print("Hi");
}

void loop() {
  delay(100);
  int a = analogRead(analogPin)/3;  // 0~1024의 값을 0~255의 값으로 맞춤
  if (a>255)  a = 255;    // 255가 넘으면 밝기가 달라지므로 255로 맞춤
  analogWrite(LED, a);    // 밝기 출력
}
