//ultra : 초음파 센서로 거리 측정

#define EchoPin 3 // Echo Port
#define TrigPin 4 // Trigger Port

int distance = 0; //거리 저장용

void ultra_setup() { 

  pinMode(TrigPin, OUTPUT);
  pinMode(EchoPin, INPUT);
} 

void ultra_loop() { 
  
  distance = getDistance(TrigPin, EchoPin);
/*
  Serial.print(distance);
  Serial.print("cm, ");
  delay(300);
*/  
} 

int getDistance (int TrPin, int EcPin) {
  digitalWrite(TrPin, LOW);
  delayMicroseconds(2);
  digitalWrite(TrPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(TrPin, LOW);
  unsigned long pulseTime = pulseIn(EcPin, HIGH);
  int distance =  (pulseTime / 2) / 29.1;
  return distance;
}
