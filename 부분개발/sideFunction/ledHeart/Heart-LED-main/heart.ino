const unsigned int led[9] = {13, 12, 11, 10, 9, 8, 7, 6, 5};

void setup() {
  for(int x=0; x<=11;x++){
      pinMode(led[x], OUTPUT);
    }
}

void loop() {
  for(int x=0;x<=8;x++){
      for(int x=0;x<=8;x++){
          digitalWrite(led[x], LOW);
        }

      digitalWrite(led[x], HIGH);

      delay(200);
      if(x==8){
        for(int x=0;x<=8;x++){
          digitalWrite(led[x], HIGH);
        }       
          delay(50000);   
      }
  }
}
