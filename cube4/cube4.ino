#include "EneLED.h"
#include <MsTimer2.h>
int c = 0;

EneLED ene;

void interrupt() {
  ene.output();
}

void setup() {
  MsTimer2::set(50, interrupt);
  MsTimer2::start();
  ene.init(2);//ボード番号2で開始
}

void loop() {
  c++;
  //  ene.led_center();
  //  delay(1000);
  //  ene.led_xax(c%3);
  //  ene.led_yax(c%3);
  //  ene.led_zax(c%3);
  ene.led_test(c % 3);
}
