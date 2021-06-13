//temp : 온도센서를 활용한 섭씨 표시
// 참고 : https://deneb21.tistory.com/541

#define TempPin A1 //Temperatura

float tempC; //섭씨 온도 표시용

void temp_setup() { 

} 

void temp_loop() { 
  int readSensor = analogRead(TempPin);
  float volt = readSensor * 5.0; //센서 공급 전압이 5V 이면 5, 3.3V 이면 3.3
  volt /= 1024.0;
  tempC = (volt - 0.5) * 100;
  /*
  Serial.print("tempC : ");
  Serial.println(tempC);
  */
  delay(500);
}
