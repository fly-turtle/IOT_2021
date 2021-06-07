//2_button

#define RED_b 4
#define GREEN_b 7
#define BLUE_b 2

#define RED 6
#define GREEN 5
#define BLUE 3

int bt_timer;

int red_count = 13; 
int red_incr = 1;
boolean gr_act = true;

void button_setup(){
  pinMode(RED_b, INPUT_PULLUP);
  pinMode(GREEN_b, INPUT_PULLUP);
  pinMode(BLUE_b, INPUT_PULLUP);

  pinMode(RED, OUTPUT);
  pinMode(GREEN, OUTPUT);
  pinMode(BLUE, OUTPUT);
  
  bt_timer = timer.setInterval(100, button_loop);
  timer.disable(bt_timer);
}


void button_loop(){
  
  if(digitalRead(RED_b) == LOW) {
    //Serial.println("RED_b");
    gr_act = true;
    three_led(0, 0, 0); //3색 LED 끄기
    /*Serial.print("red_count : ");
    Serial.println(red_count);
    Serial.println(digitalRead(8));*/
    digitalWrite(red_count, digitalRead(red_count)^1);
    red_count -= red_incr;
    if(red_count <= 8){
      red_incr *= -1;
      red_count = 8;
    }
    if(red_count >= 13){
      red_incr *= -1;
      red_count = 13;
    }
    
  }
  if(digitalRead(GREEN_b) == LOW) {
    //Serial.println("GREEN_b");
    red_count = 13;
    three_led(0, 0, 0); //3색 LED 끄기
    if(gr_act == true){  //gr_act == true 이면 LED들 초기셋팅
      for(int i = 13; i>= 8; i-=2){
        digitalWrite(i, HIGH);
      }
      for(int i = 12; i>= 8; i-=2){
        digitalWrite(i, LOW);
      }
      gr_act = false;
    }
    else {
      for(int i = 13; i>= 8; i--){
        digitalWrite(i, digitalRead(i)^1);
      } 
    }
  }
  if(digitalRead(BLUE_b) == LOW) {
    //Serial.println("BLUE_b");
    for(int i = 8; i<=13; i++){
      digitalWrite(i, LOW);
    }
    three_led(random(0,255),random(0,255),random(0,255));
    red_count = 13;
    gr_act = true;
  }
}

void three_led(int red, int blue, int green){
  analogWrite(RED, red);
  analogWrite(BLUE, blue);
  analogWrite(GREEN, green); 
}
