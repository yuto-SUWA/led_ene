#include <MsTimer2.h>

#define y0 1000
#define ac 9.8

int tim=0;
float height;
void setup() {
  Serial.begin(115200);
  MsTimer2::set(100, timerInt);
  MsTimer2::start();
}

void loop() {
  delay(100);
  Serial.println(height);
}

void timerInt() {
  tim=tim+100;
  height=y0-0.5*ac*tim*tim/1000;
}
