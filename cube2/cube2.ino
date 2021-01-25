#include <SPI.h>

#define SRCLK   (13)    // SPI:CLOCK
#define RCLK    (6)
#define SER     (11)    // SPI:MOSI

void setup() {
  pinMode(SRCLK, OUTPUT);
  pinMode(RCLK,  OUTPUT);
  pinMode(SER,   OUTPUT);

  SPI.begin();
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
}

// 点灯パターン(1=点灯, 0=消灯)
const uint8_t PATTERNS[] = {
  0b11111111,
  0b11111111,
  0b00000010,
  0b00000100,
  0b00001000,
  0b00010000,
  0b00100000,
  0b00000100,
  0b00001000,
  0b00010000,
  0b00100000,
  0b00000010,
  0b00001000,
  0b00010000,
  0b00100000,
  0b00000010,
  0b00000100,
};

void loop() {

  // 点灯パターンの数
  int max_pattern = sizeof(PATTERNS)/sizeof(PATTERNS[0]);

  for (uint8_t i=0; i<max_pattern; i++) {
    // 8ビット分のデータをシフトレジスタへ送る
    SPI.transfer(PATTERNS[i]);

    // シフトレジスタの状態をストアレジスタへ反映させる
    digitalWrite(RCLK,  LOW);
    digitalWrite(RCLK,  HIGH);

  }
    delay(1000);
}
