//5_ultra_servo

int ultra_servo_timer;

void ultra_servo_setup(){
  ultra_servo_timer = timer.setInterval(50, ultra_servo_loop);
  timer.disable(ultra_servo_timer);
}

void ultra_servo_loop(){
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 17/1000;
  Serial.println(distance);
  if (distance <= 10){
    servo.write(90);
  }
  else
    servo.write(0);
  //delay(500);
}
