//poten : potentiometer 가변저항

#define PotenPin A0 // 가변저항

int Val = 0; //저항 세기 저장용

void poten_setup() { 
  
} 

void poten_loop() { 
  int potenVal = analogRead(PotenPin);
  //Serial.println(potenVal);
  Val = map(potenVal,  0, 1023, 10, 100);
  Val = constrain(Val, 10, 100); //val 이 10~100 사이에 있도록 제한합니다.
  /*
  Serial.print("register:");
  Serial.print(potenVal);
  Serial.print(", Val:");
  Serial.println(Val); 
  */

}
