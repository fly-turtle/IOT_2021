//1_led_digi

#define RED 13
#define BLUE 12

int led_digi_timer; // timer 활용

void led_digi_setup(){
  pinMode(RED, OUTPUT);
  pinMode(BLUE, OUTPUT);

 /* digitalWrite(RED, HIGH); // 아날로그와 병행 처리 시
  digitalWrite(BLUE, LOW); */
  led_digi_timer = timer.setInterval(500, led_digi_loop);
  timer.disable(led_digi_timer);
}

void led_digi_loop(){
/*  digitalWrite(RED, HIGH);
  digitalWrite(BLUE, LOW);
  delay(500);

  digitalWrite(RED, LOW);
  digitalWrite(BLUE, HIGH);
  delay(500);
*/
//  digitalWrite(BLUE, digitalRead(BLUE)^1); // 한 줄 작성 샘플
  digitalWrite(BLUE, digitalRead(BLUE)^1);  // 아날로그와 병행 처리 시
  digitalWrite(RED, digitalRead(RED)^1);  
}
