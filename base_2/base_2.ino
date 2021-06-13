//base_2 선풍기 제작

void setup(){
  Serial.begin(9600);
  poten_setup();
  ultra_setup();
  temp_setup();
  run_setup();
}

void loop(){
  poten_loop();
  ultra_loop();
  temp_loop();
  run_loop();
}
