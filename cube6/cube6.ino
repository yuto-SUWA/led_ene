#include "EneLED2.h"
#include <MsTimer2.h>

#define red_Button 5
#define green_Button 7
#define blue_Button 8
EneLED ene;


void interrupt()
{ ene.color = digitalRead(5) + digitalRead(7) * 2 + digitalRead(8) * 4;
  ene.output();
  //Serial.print(c);
}


void setup() {
  //Serial.begin(9600);
  MsTimer2::set(2, interrupt);
  MsTimer2::start();
  ene.init(1);
}

void loop() {

  ene.led_suwa();
  //delay(2000);

  while (1) {
    if ( (digitalRead(5) == 0) && ( digitalRead(7) == 0) && ( digitalRead(8) == 0)) {
      break;
    }
    int y = random(3);
    switch (y) {

      case 0:
        for (int t = 3; t > 0; t--)
        {
          ene.led_default();
          if ( (digitalRead(5) == 0) && ( digitalRead(7) == 0) && ( digitalRead(8) == 0)) {
            t = 0;
          }
        }
        break;
      case 1:
        for (int t = 20; t > 0; t--)
        {
          ene.falldown();
          if ( (digitalRead(5) == 0) && ( digitalRead(7) == 0) && ( digitalRead(8) == 0)) {
            t = 0;
          }
        }
        break;
      case 2:
        for (int t = 10; t > 0; t--)
        {
          ene.text(t);
          if ( (digitalRead(5) == 0) && ( digitalRead(7) == 0) && ( digitalRead(8) == 0)) {
            t = 0;
          }
        }
        break;

    }
  }
  ene.led_test();
}
