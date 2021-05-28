//serial_menu

int input_menu = 0;

void serial_setup(){
  show_menu();
}

void serial_loop(){
  if(Serial.available()>0){
    input_menu = Serial.read();
    if(input_menu != char(10)){
      Serial.print("사용자 선택 : ");
      Serial.println((char)input_menu);
    }

    switch(input_menu){
      case '1':
        timer.enable(sound_bar_timer);
        timer.disable(bt_timer);
        led_off();
        break;

      case '2':
        timer.disable(sound_bar_timer);
        timer.enable(bt_timer);
        led_off();
        break;        

      case '8':
        timer.disable(sound_bar_timer);
        timer.disable(bt_timer);
        led_off();
        break;

      case char(10):
        break;

      default:
        Serial.println("1, 2, 8을 입력하세요.");
        break;      
    }
  }
  
}


void show_menu(){
  Serial.println("1. Sound bar");
  Serial.println("2. button & led control");  
  Serial.println("8. All stop");  
}
