//2_led_anal

#define YELLOW 11

int led_anal_timer; //timer 활용

int i = 0;
int gap = 30;

void led_anal_setup(){
  pinMode(YELLOW, OUTPUT);

  led_anal_timer = timer.setInterval(200, led_anal_loop);
  timer.disable(led_anal_timer);
}

void led_anal_loop(){

/*  for(int i = 0; i <= 255; i += 10){
    analogWrite(YELLOW, i);
    delay(50);
  }

  for(int i = 255; i >= 0; i -= 10){
    analogWrite(YELLOW, i);
    delay(50);
  }  
*/
  
  analogWrite(YELLOW, i);
  i += gap;
  if( i >= 255 ){
    gap *= -1;
    i = 255;
  }
  if( i <= 0 ){
    gap *= -1;
    i = 0;
  }
 
//  delay(50);
    
//  Serial.print("i : ");
//  Serial.println(i);
  
}
