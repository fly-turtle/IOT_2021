//3_sound

#define sound A0

int sound_timer; // timer 활용

void sound_setup(){
  for(int i = 7; i<=13; i++){
    pinMode(i, OUTPUT);
  }
  sound_timer = timer.setInterval(100, sound_loop);
  timer.disable(sound_timer);  
}

void sound_loop(){
  for(int i = 7; i<=13; i++){
    digitalWrite(i, LOW);
  }
  int sound_chk = map(analogRead(A0), 0, 900, 6, 14); //내일 이거 가지고 Jukbox
//  Serial.print("sound : ");
//  Serial.println(analogRead(A0));
  for(int i = 7; i<=sound_chk; i++){
    digitalWrite(i, HIGH);
  }

}
