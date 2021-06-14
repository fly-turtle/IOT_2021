//1_sound_bar

#define sound A0

int sound_bar_timer; // timer 활용

void sound_setup(){
  for(int i = 8; i<=13; i++){
    pinMode(i, OUTPUT);
  }
  sound_bar_timer = timer.setInterval(100, sound_loop);
  timer.disable(sound_bar_timer);  
}

void sound_loop(){
  for(int i = 8; i<=13; i++){
    digitalWrite(i, LOW);
  }
  int sound_chk = map(analogRead(sound), 0, 900, 7, 14);
  sound_chk = constrain(sound_chk, 7, 13);
//  Serial.print("sound : ");
//  Serial.println(analogRead(A0));
  for(int i = 8; i<=sound_chk; i++){
    digitalWrite(i, HIGH);
  }

}
