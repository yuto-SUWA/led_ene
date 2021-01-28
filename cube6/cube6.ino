#include "EneLED2.h"
#include <MsTimer2.h>
int c = 0;

EneLED ene;

void interrupt() {
  ene.output();
}

void setup() {
  MsTimer2::set(2, interrupt);
  MsTimer2::start();
  ene.init(1);
}

void loop() {
  ene.led_full(0b010);
}
