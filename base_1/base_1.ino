//base_1

#include <SimpleTimer.h>

SimpleTimer timer;


void setup() {
  Serial.begin(9600);

  sound_setup();
  button_setup();
  serial_setup();
  ir_setup();

}

void loop() {
  timer.run();

  //button_loop();
  ir_loop();
  serial_loop();

}
