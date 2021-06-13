//run : 실제 선풍기 돌리는 탭

#define LedPin 7
#define UsbPin 11

void run_setup() { 
  pinMode(UsbPin, OUTPUT);
  pinMode(LedPin, OUTPUT);
} 

void run_loop() {
  Serial.print("현재 온도 : ");
  Serial.println(tempC); 
  Serial.print("거리 : ");
  Serial.println(distance);
  Serial.print("세기 : ");
  Serial.println(Val);
  if(tempC >= 30){
    if (distance < 15 || distance > Val) { //너무 가깝거나 너무 멀어지면
      digitalWrite(LedPin, HIGH);
      delay(100);
      digitalWrite(LedPin, LOW);
      delay(100);
    } 
    if (distance >= 15 && distance <= Val) {
      digitalWrite(LedPin, HIGH);
      digitalWrite(UsbPin, 255);
      delay(1000);
    } 
    else {
      digitalWrite(LedPin, LOW);
      digitalWrite(UsbPin, LOW);
      delay(100);
    }
  }
  
} 
