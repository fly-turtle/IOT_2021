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
        timer.enable(led_digi_timer);
        digitalWrite(RED, HIGH); //빨강 LED의 첫 값을 HIGH로 설정
        timer.disable(led_anal_timer);
        //digitalWrite(YELLOW, LOW); //노랑 LED 끄고
        analogWrite(YELLOW, 0);
        i = 0;  //i 값을 초기화
        timer.disable(sound_timer);
        timer.disable(ultra_timer);
        timer.disable(servo_timer);
        timer.disable(ultra_servo_timer);
        servo.detach(); //9번 핀, 10번 핀
        timer.disable(buzzer_timer);
        break;

      case '2':
        timer.disable(led_digi_timer);
        digitalWrite(RED, LOW);
        digitalWrite(BLUE, LOW);        
        timer.enable(led_anal_timer);
        timer.disable(sound_timer);
        timer.disable(ultra_timer);
        timer.disable(servo_timer);
        timer.disable(ultra_servo_timer);
        servo.detach();
        timer.disable(buzzer_timer);
        break;


      case '3':
        timer.disable(led_digi_timer);
        digitalWrite(RED, LOW); // LED 끄기
        digitalWrite(BLUE, LOW);        
        timer.disable(led_anal_timer);
        //digitalWrite(YELLOW, LOW);        
        analogWrite(YELLOW, 0);
        i = 0;
        timer.enable(sound_timer);
        timer.disable(ultra_timer);
        timer.disable(servo_timer);
        timer.disable(ultra_servo_timer);
        servo.detach();
        timer.disable(buzzer_timer);
        break;


      case '4':
        timer.disable(led_digi_timer);
        digitalWrite(RED, LOW); // LED 끄기
        digitalWrite(BLUE, LOW);        
        timer.disable(led_anal_timer);
        //digitalWrite(YELLOW, LOW);
        analogWrite(YELLOW, 0);
        i = 0;
        timer.disable(sound_timer);
        timer.enable(ultra_timer);
        timer.disable(servo_timer);
        timer.disable(ultra_servo_timer);
        servo.detach();
        timer.disable(buzzer_timer);
        break;


      case '5':
        timer.disable(led_digi_timer);
        digitalWrite(RED, LOW); // LED 끄기
        digitalWrite(BLUE, LOW);        
        timer.disable(led_anal_timer);
        //digitalWrite(YELLOW, LOW);
        analogWrite(YELLOW, 0);
        i = 0;
        timer.disable(sound_timer);
        timer.disable(ultra_timer);
        servo.attach(servo_pin);
        timer.enable(servo_timer);
        timer.disable(ultra_servo_timer);
        timer.disable(buzzer_timer);
        break;

      case '6':
        timer.disable(led_digi_timer);
        digitalWrite(RED, LOW); // LED 끄기
        digitalWrite(BLUE, LOW);        
        timer.disable(led_anal_timer);
        //digitalWrite(YELLOW, LOW);
        analogWrite(YELLOW, 0);
        i = 0;
        timer.disable(sound_timer);
        timer.disable(ultra_timer);
        timer.disable(servo_timer);
        servo.attach(servo_pin);
        timer.enable(ultra_servo_timer);
        timer.disable(buzzer_timer);
        break;


      case '7':
        timer.disable(led_digi_timer);
        digitalWrite(RED, LOW); // LED 끄기
        digitalWrite(BLUE, LOW);        
        timer.disable(led_anal_timer);
        //digitalWrite(YELLOW, LOW);
        analogWrite(YELLOW, 0);
        i = 0;
        timer.disable(sound_timer);
        timer.disable(ultra_timer);
        timer.disable(servo_timer);
        timer.disable(ultra_servo_timer);
        servo.detach();
        timer.enable(buzzer_timer);
        break;

      case '8':
        timer.disable(led_digi_timer);
        digitalWrite(RED, LOW); // LED 끄기
        digitalWrite(BLUE, LOW);        
        timer.disable(led_anal_timer);
        //digitalWrite(YELLOW, LOW);
        analogWrite(YELLOW, 0);
        i = 0;
        timer.disable(sound_timer);
        timer.disable(ultra_timer);
        timer.disable(servo_timer);
        timer.disable(ultra_servo_timer);
        servo.detach();
        timer.disable(buzzer_timer);
        show_menu();
        break;
                
      case char(10):
        break;

      default:
        Serial.println("1~8까지 입력하세요.");
        break;      
    }
  }
  
}


void show_menu(){
  Serial.println("1. digit control LED");
  Serial.println("2. analog control LED");
  Serial.println("3. sound meter");
  Serial.println("4. ultra distance");
  Serial.println("5. servo control");
  Serial.println("6. ultra & servor control");
  Serial.println("7. buzzer melody");
  Serial.println("8. All stop");  
}
