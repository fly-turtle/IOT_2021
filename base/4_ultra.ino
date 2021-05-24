//4_ultra

//http://raduino.tistory.com/28 : 초음파 센서를 통한 거리측정

#define TRIG 5
#define ECHO 4

int ultra_timer; // timer 활용

long duration, distance;

void ultra_setup(){
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  ultra_timer = timer.setInterval(1000, ultra_loop);
  timer.disable(ultra_timer);
}

void ultra_loop(){

  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 17/1000;

//  Serial.print("Duration : ");
//  Serial.println(duration);

  Serial.print("Distance : ");
  Serial.print(distance);
  Serial.println(" cm");

  //delay(1000);
}
