#include <Servo.h>

const int SERVO = 4;
Servo servo;

const unsigned int led[8] = {13, 12, 11, 10, 9, 8, 7, 6};
int x=0;


const int BUZZER = 0;
char note[] = "egCDBAAggAedc0CDBAAggpA00gCDBAAggBC0fefgedcadc";
char beat[] = "2243322243215043322242710243322243802123212225";
int note_length = sizeof(note)/sizeof(note[0])-1;

int tempo = 130;

int freq(char note) {
  char note_name[] = {'0', 'a', 'b', 'c', 'd', 'e', 'f', 'g', 'A', 'p','B', 'C', 'D'};
  int note_freq[] = {0, 440, 494, 523, 587, 659, 698, 784, 880, 932, 987, 1047, 1174};

  for (int i = 0; i < sizeof(note_name)/sizeof(note_name[0]);i++) {
      if(note_name[i] == note) {
        return note_freq[i];
      }
  }
}

int duration(char beat) {
  return beat - '0';
}


const unsigned int FND[7] = {A1,A2,A3,A4,A5,2,3};
const unsigned int num[11][7] = {
  {1,1,1,1,0,1,1,},/*9*/
  {1,1,1,1,1,1,1,},/*8*/
  {1,1,1,0,0,1,0,},/*7*/
  {1,0,1,1,1,1,1,},/*6*/
  {1,0,1,1,0,1,1,},/*5*/
  {0,1,1,0,0,1,1,},/*4*/
  {1,1,1,1,0,0,1,},/*3*/
  {1,1,0,1,1,0,1,},/*2*/
  {0,1,1,0,0,0,0,},/*1*/ 
  {1,1,1,1,1,1,0,},/*0*/
  {0,0,0,0,0,0,0,},/*off*/
  };

void display_init() {
  for (int x = 0; x<7; x++)
    pinMode(FND[x], OUTPUT);
}

void display_clear() {
  for (int x = 0; x<7; x++)
    digitalWrite(FND[x], LOW);
}

void display_number(int n) {
  if(0<=n&&n<=9){
    for(int x=0;x<7;x++)
      digitalWrite(FND[x], num[n][x] == 1?HIGH:LOW);
  }
}    





void setup() {
  servo.attach(SERVO);
  servo.write(45);
 
  for(int x=0; x<8;x++){
      pinMode(led[x], OUTPUT);  // 13,12,11,10,9,8,7,6핀 출력
    }
  pinMode(A0, INPUT);    // A0핀 입력
  display_init();
}



void loop() {
  if (digitalRead(A0) == 1) {
    for(x=0; x<8; x++) {
      for(int y=0;y<8;y++)
        digitalWrite(led[y], LOW);
  
      digitalWrite(led[x], HIGH);
      delay(200);
    }
    for(int y=0;y<=8;y++)
      digitalWrite(led[y], HIGH);
    
    delay(500);
 
    for(int i=0;i<note_length;i++) {
      if(note[i] != ' ') {
        tone(BUZZER, freq(note[i]));
      }
      delay (tempo*duration(beat[i]));

      noTone(BUZZER);
      delay(100);
    }
    delay(3000);
    for(int n=0;n<=10;n++){
      display_clear();
      display_number(n);

      delay(480);
      for(int angle=45; angle<=135;angle++){
        servo.write(angle);
        delay(3);
      }
      delay(480);
      
      for(int angle=135; angle>=45;angle--){
        servo.write(angle);
        delay(3);
      }
    }
  }
}
