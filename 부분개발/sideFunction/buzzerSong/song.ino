const int BUZZER = 4;
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

void setup() {
  for(int i=0;i<note_length;i++) {
      if(note[i] != ' ') {
        tone(BUZZER, freq(note[i]));
      }
      delay (tempo*duration(beat[i]));

      noTone(BUZZER);
      delay(100);
  }
}
void loop() {

}
