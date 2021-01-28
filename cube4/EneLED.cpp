#include <Arduino.h>
#include "EneLED.h"

EneLED::EneLED(void) {
}

void EneLED::init(int board) {
  board_no = board;
  pinMode(13, OUTPUT);
  pinMode(6,  OUTPUT);
  pinMode(11, OUTPUT);
  SPI.begin();
  SPI.beginTransaction(SPISettings(1000000, MSBFIRST, SPI_MODE0));
}

void EneLED::led_xax(int color) {
  led_clear();
  for (int i = 0; i < 5; i++) {
    led_gnd[i] = 1;
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      switch (color) {
        case 0:
          led_red[i - 1][j] = 0;
          led_red[i][j] = 1;
          break;
        case 1:
          led_gre[i - 1][j] = 0;
          led_gre[i][j] = 1;
          break;
        case 2:
          led_blu[i - 1][j] = 0;
          led_blu[i][j] = 1;
          break;
      }
    }
    delay(200);
  }
}

void EneLED::led_yax(int color) {
  led_clear();
  for (int i = 0; i < 5; i++) {
    led_gnd[i] = 1;
  }
  for (int j = 0; j < 5; j++) {
    for (int i = 0; i < 5; i++) {
      switch (color) {
        case 0:
          led_red[i][j - 1] = 0;
          led_red[i][j] = 1;
          break;
        case 1:
          led_gre[i][j - 1] = 0;
          led_gre[i][j] = 1;
          break;
        case 2:
          led_blu[i][j - 1] = 0;
          led_blu[i][j] = 1;
          break;
      }
    }
    delay(200);
  }
}

void EneLED::led_test(int color) {
  led_clear();
  for (int i = 0; i < 5; i++) {
    led_gnd[i - 1] = 0;
    led_gnd[i] = 1;
    for (int j = 0; j < 5; j++) {
      for (int i = 0; i < 5; i++) {
        switch (color) {
          case 0:
            led_red[i - 1][j] = 0;
            led_red[i][j] = 1;
            break;
          case 1:
            led_gre[i - 1][j] = 0;
            led_gre[i][j] = 1;
            break;
          case 2:
            led_blu[i - 1][j] = 0;
            led_blu[i][j] = 1;
            break;
        }
        led_red[4][j - 1] = 0;
        led_blu[4][j - 1] = 0;
        led_gre[4][j - 1] = 0;
        delay(100);
      }
      led_red[4][4] = 0;
      led_blu[4][4] = 0;
      led_gre[4][4] = 0;
    }
  }
}

void EneLED::led_center() {
  led_clear();
  for (int i = 1; i < 4; i++) {
    led_gnd[i] = 1;
  }
  for (int i = 1; i < 4; i++) {
    for (int j = 1; j < 4; j++) {
      led_red[i][j] = 1;
      led_gre[i][j] = 1;
      led_blu[i][j] = 1;
    }
  }
}

void EneLED::led_zax(int color) {
  led_clear();
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      switch (color) {
        case 0:
          led_red[i][j] = 1;
          break;
        case 1:
          led_gre[i][j] = 1;
          break;
        case 2:
          led_blu[i][j] = 1;
          break;
      }
    }
  }
  for (int i = 0; i < 5; i++) {
    led_gnd[i - 1] = 0;
    led_gnd[i] = 1;
    delay(200);
  }
}

void EneLED::led_clear() {
  for (int i = 0; i < 5; i++) {
    led_gnd[i] = 0;
  }
  for (int i = 0; i < 5; i++) {
    for (int j = 0; j < 5; j++) {
      led_red[i][j] = 0;
      led_gre[i][j] = 0;
      led_blu[i][j] = 0;
    }
  }
}

void EneLED::output() {
  led_swap();
  for (int i = 0; i < 17; i++) { //LED_GND
    SPI.transfer(PATTERNS[i]);
    digitalWrite(6,  LOW);
    digitalWrite(6,  HIGH);
  }
}

void EneLED::led_swap() {
  //switch (board_no) {
    //case 1:
      //1
      PATTERNS[0] = {1 * led_gnd[0] + 2 * led_gnd[4] + 4 * led_gnd[3]
                 + 8 * led_gnd[1] + 16 * led_gnd[2] + 32 * led_gnd[1]
                 + 64 * led_gnd[2] + 128 * led_gnd[3]
                };
  PATTERNS[1] = {1 * led_gnd[0] + 2 * led_gnd[4] + 4 * led_gnd[3]
                 + 8 * led_gnd[0] + 16 * led_gnd[4] + 32 * led_gnd[3]
                 + 64 * led_gnd[2] + 128 * led_gnd[1]
                };

      PATTERNS[2] = {2 * led_red[1][4] + 4 * led_red[0][4] + 8 * led_red[2][4]
                     + 16 * led_red[3][4] + 32 * led_red[4][4]
                  };
      PATTERNS[3] = {2 * led_red[1][3] + 4 * led_red[0][3] + 8 * led_red[2][3]
                     + 16 * led_red[3][3] + 32 * led_red[4][3]
                  };
      PATTERNS[4] = {2 * led_red[1][2] + 4 * led_red[0][2] + 8 * led_red[2][2]
                     + 16 * led_red[3][2] + 32 * led_red[4][2]
                  };
      PATTERNS[5] = {2 * led_red[1][1] + 4 * led_red[0][1] + 8 * led_red[2][1]
                     + 16 * led_red[3][1] + 32 * led_red[4][1]
                  };
      PATTERNS[6] = {2 * led_red[1][0] + 4 * led_red[0][0] + 8 * led_red[2][0]
                     + 16 * led_red[3][0] + 32 * led_red[4][0]
                  };

      PATTERNS[7] = {2 * led_blu[1][4] + 4 * led_blu[0][4] + 8 * led_blu[2][4]
                     + 16 * led_blu[3][4] + 32 * led_blu[4][4]
                  };
      PATTERNS[8] = {2 * led_blu[1][3] + 4 * led_blu[0][3] + 8 * led_blu[2][3]
                     + 16 * led_blu[3][3] + 32 * led_blu[4][3]
                  };
      PATTERNS[9] = {2 * led_blu[1][2] + 4 * led_blu[0][2] + 8 * led_blu[2][2]
                     + 16 * led_blu[3][2] + 32 * led_blu[4][2]
                  };
      PATTERNS[10] = {2 * led_blu[1][1] + 4 * led_blu[0][1] + 8 * led_blu[2][1]
                      + 16 * led_blu[3][1] + 32 * led_blu[4][1]
                   };
      PATTERNS[11] = {2 * led_blu[1][0] + 4 * led_blu[0][0] + 8 * led_blu[2][0]
                      + 16 * led_blu[3][0] + 32 * led_blu[4][0]
                   };

      PATTERNS[12] = {2 * led_gre[1][4] + 4 * led_gre[0][4] + 8 * led_gre[4][4]
                      + 16 * led_gre[3][4] + 32 * led_gre[2][4]
                   };
      PATTERNS[13] = {2 * led_gre[1][3] + 4 * led_gre[0][3] + 8 * led_gre[4][3]
                      + 16 * led_gre[3][3] + 32 * led_gre[2][3]
                   };
      PATTERNS[14] = {2 * led_gre[1][2] + 4 * led_gre[0][2] + 8 * led_gre[4][2]
                      + 16 * led_gre[3][2] + 32 * led_gre[2][2]
                   };
      PATTERNS[15] = {2 * led_gre[1][1] + 4 * led_gre[0][1] + 8 * led_gre[4][1]
                      + 16 * led_gre[3][1] + 32 * led_gre[2][1]
                   };
      PATTERNS[16] = {2 * led_gre[1][0] + 4 * led_gre[0][0] + 8 * led_gre[4][0]
                      + 16 * led_gre[3][0] + 32 * led_gre[2][0]
                   };
      /*break;
    case 2:
      //2
      PATTERNS[0] = {1 * led_gnd[0] + 2 * led_gnd[1] + 4 * led_gnd[2]
                     + 8 * led_gnd[4] + 32 * led_gnd[4] + 64 * led_gnd[3]
                  };
      PATTERNS[1] = {1 * led_gnd[0] + 2 * led_gnd[1] + 4 * led_gnd[2]
                     + 8 * led_gnd[0] + 16 * led_gnd[1] + 32 * led_gnd[2]
                     + 64 * led_gnd[3]
                  };

      PATTERNS[2] = {2 * led_red[1][4] + 4 * led_red[0][4] + 8 * led_red[2][4]
                     + 16 * led_red[3][4] + 32 * led_red[4][4]
                  };
      PATTERNS[3] = {2 * led_red[1][3] + 4 * led_red[0][3] + 8 * led_red[2][3]
                     + 16 * led_red[3][3] + 32 * led_red[4][3]
                  };
      PATTERNS[4] = {2 * led_red[1][2] + 4 * led_red[0][2] + 8 * led_red[2][2]
                     + 16 * led_red[3][2] + 32 * led_red[4][2]
                  };
      PATTERNS[5] = {2 * led_red[1][1] + 4 * led_red[0][1] + 8 * led_red[2][1]
                     + 16 * led_red[3][1] + 32 * led_red[4][1]
                  };
      PATTERNS[6] = {2 * led_red[1][0] + 4 * led_red[0][0] + 8 * led_red[2][0]
                     + 16 * led_red[3][0] + 32 * led_red[4][0]
                  };

      PATTERNS[7] = {2 * led_blu[1][4] + 4 * led_blu[0][4] + 8 * led_blu[4][4]
                     + 16 * led_blu[3][4] + 32 * led_blu[2][4]
                  };
      PATTERNS[8] = {2 * led_blu[1][3] + 4 * led_blu[0][3] + 8 * led_blu[4][3]
                     + 16 * led_blu[3][3] + 32 * led_blu[2][3]
                  };
      PATTERNS[9] = {2 * led_blu[1][2] + 4 * led_blu[0][2] + 8 * led_blu[4][2]
                     + 16 * led_blu[3][2] + 32 * led_blu[2][2]
                  };
      PATTERNS[10] = {2 * led_blu[1][1] + 4 * led_blu[0][1] + 8 * led_blu[4][1]
                      + 16 * led_blu[3][1] + 32 * led_blu[2][1]
                   };
      PATTERNS[11] = {2 * led_blu[1][0] + 4 * led_blu[0][0] + 8 * led_blu[4][0]
                      + 16 * led_blu[3][0] + 32 * led_blu[2][0]
                   };

      PATTERNS[12] = {2 * led_gre[1][4] + 4 * led_gre[0][4] + 8 * led_gre[2][4]
                      + 16 * led_gre[3][4] + 32 * led_gre[4][4]
                   };
      PATTERNS[13] = {2 * led_gre[1][3] + 4 * led_gre[0][3] + 8 * led_gre[2][3]
                      + 16 * led_gre[3][3] + 32 * led_gre[4][3]
                   };
      PATTERNS[14] = {2 * led_gre[1][2] + 4 * led_gre[0][2] + 8 * led_gre[2][2]
                      + 16 * led_gre[3][2] + 32 * led_gre[4][2]
                   };
      PATTERNS[15] = {2 * led_gre[1][1] + 4 * led_gre[0][1] + 8 * led_gre[2][1]
                      + 16 * led_gre[3][1] + 32 * led_gre[4][1]
                   };
      PATTERNS[16] = {2 * led_gre[1][0] + 4 * led_gre[0][0] + 8 * led_gre[2][0]
                      + 16 * led_gre[3][0] + 32 * led_gre[4][0]
                   };
      break;
  }*/
}
