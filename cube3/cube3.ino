#include <SPI.h>

#define SRCLK   (13)    // SPI:CLOCK
#define RCLK    (6)
#define SER     (11)    // SPI:MOSI

int c = 1;
int c1 = 4;
int c2 = 8;

void setup() {
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK,  OUTPUT);
  pinMode(SER,   OUTPUT);

  SPI.begin();
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
}

static int pika[]={
  0b00000010,
  0b00000100,
  0b00001000,
  0b00010000,
  0b00100000,
};

const uint8_t PATTERNS[] = {
  0b00000010,
  0b00000100,
  0b00001000,
  0b00010000,
  0b00100000,
};


void loop() {
  c++;
  if (c > 5)c = 0;
  //いしゅお
  for (int i = 0; i < 2; i++) { //LED_GND
    SPI.transfer(0b11111111);
    digitalWrite(RCLK,  LOW);
    digitalWrite(RCLK,  HIGH);
  }
  for (int i = 0; i < 5; i++) { //LED_RED
    SPI.transfer(0);
    digitalWrite(RCLK,  LOW);
    digitalWrite(RCLK,  HIGH);
  }
  for (int i = 0; i < 5; i++) { //LED_BLUE
    SPI.transfer(PATTERNS[c]);
    digitalWrite(RCLK,  LOW);
    digitalWrite(RCLK,  HIGH);
  }
  for (int i = 0; i < 5; i++) { //LED_GREEN
    SPI.transfer(0);
    digitalWrite(RCLK,  LOW);
    digitalWrite(RCLK,  HIGH);
  }
  delay(1000);
  //よしこぉ
}
