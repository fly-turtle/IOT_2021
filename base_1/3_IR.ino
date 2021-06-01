//IR

#include <IRremote.h>

int RECV_PIN = A1;

IRrecv irrecv(RECV_PIN);
decode_results results;

void ir_setup(){
  irrecv.enableIRIn();
}

void ir_loop() {
  if (irrecv.decode(&results)) {
    //Serial.println(results.value, HEX); // 시리얼 모니터에 리모콘 버튼의 고유값 출력
    switch (results.value) { // 리모콘 버튼의 고유값에 따라
      case 0xFF30CF : // 리모콘의 1버튼이 눌리면,
        Serial.println("1번");
        timer.enable(sound_bar_timer);
        timer.disable(bt_timer);
        led_off();
        break;
      case 0xFF18E7: // 리모콘의 2버튼이 눌리면,
        Serial.println("2번");
        timer.disable(sound_bar_timer);
        timer.enable(bt_timer);
        led_off();
        break;
      case 0xFF7A85:  // 리모콘의 3버튼이 눌리면, 
        break;
      case 0xFF10EF :// 리모콘의 4버튼이 눌리면,
        break;
      case 0xFF38C7:  // 리모콘의 5버튼이 눌리면,
        break;
      case 0xFF5AA5: // 리모콘의 6버튼이 눌리면, 
        break;
      case 0xFF42BD : // 리모콘의 7버튼이 눌리면,
        break;        
      case 0xFF4AB5: // 리모콘의 8버튼이 눌리면,
        Serial.println("8번");      
        timer.disable(sound_bar_timer);
        timer.disable(bt_timer);
        led_off();
        break;
      case 0xFF52AD: // 리모콘의 9버튼이 눌리면,
        break;
      default:
        break;                
    }
    irrecv.resume(); // 다음 값을 받는다.
  }
}


void led_off(){
  for(int i = 8; i >= 13; i++){
    digitalWrite(i, LOW);
  }
  analogWrite(RED,0);
  analogWrite(BLUE,0);
  analogWrite(GREEN,0);
  red_count = 13;
  gr_act = true;        
}
