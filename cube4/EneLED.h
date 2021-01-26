#ifndef EneLED_h
#define EneLED_h
#include <Arduino.h>
#include <SPI.h>

class EneLED{
  public:
    EneLED();
    void init(int board);      //初期化
    void led_xax(int color);//0=R,1=G,2=B
    void led_yax(int color);//0=R,1=G,2=B
    void led_clear();
    void output();    //出力
    void led_zax(int color);
    void led_center();
  private:
    uint8_t PATTERNS[17];//最終出力バッファ
    void led_swap();
    int board_no;
    int led_gnd[5];
    int led_red[5][5];
    int led_blu[5][5];
    int led_gre[5][5];
};
#endif
