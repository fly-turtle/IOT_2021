//base

#include <SimpleTimer.h>

SimpleTimer timer;


void setup() {
  Serial.begin(9600);
  
  led_digi_setup();
  led_anal_setup();
  sound_setup();
  ultra_setup();
  servo_setup();
  Buzzer_setup();

  serial_setup();

}

void loop() {

  timer.run();
//  Buzzer_loop();
//  led_digi_loop();
//  led_anal_loop();
//  sound_loop();
//  ultra_loop();
//  servo_loop();

  serial_loop();
}
