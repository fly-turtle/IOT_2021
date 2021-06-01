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
    if(gr_act == true){
      for(int i = 13; i>= 8; i-=2){
        digitalWrite(i, HIGH);
      }
      gr_act = false;
    }
    else {
      for(int i = 13; i>= 8; i-=2){
        digitalWrite(i, digitalRead(i)^1);
      }
      for(int i = 12; i>= 8; i-=2){
      digitalWrite(i, digitalRead(i)^1);
      }  
    }
  }
  if(digitalRead(BLUE_b) == LOW) {
    //Serial.println("BLUE_b");
    for(int i = 8; i<=13; i++){
      digitalWrite(i, LOW);
    }
    analogWrite(RED,random(0, 255));
    analogWrite(BLUE,random(0, 255));
    analogWrite(GREEN,random(0, 255));
    red_count = 13;
    gr_act = true;
  }
}
