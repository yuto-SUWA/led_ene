/* リモコンテスト用
*/
#include <IRremote.h>

IRrecv irrecv(8);

void  setup ( )
{
  Serial.begin(115200);
  irrecv.enableIRIn();
}

void  loop ( )
{
  decode_results  results;
  if (irrecv.decode(&results)) {
    switch(results.value){
      case 0xA90:
        Serial.println("電源");
        break;
      case 0x3758:
        Serial.println("サッカーモード");
        break;
      case 0xA50:
        Serial.println("入力切替");
        break;
      case 0x54E9:
        Serial.println("連動データ");
        break;
      case 0x3923:
        Serial.println("スカパープレミアム");
        break;
      case 0x4E9:
        Serial.println("BS/CS");
        break;
      case 0x26E9:
        Serial.println("地デジ");
        break;
      case 0x10:
        Serial.println("1");
        break;
      case 0x810:
        Serial.println("2");
        break;
      case 0x410:
        Serial.println("3");
        break;
      case 0xC10:
        Serial.println("4");
        break;
      case 0x210:
        Serial.println("5");
        break;
      case 0xA10:
        Serial.println("6");
        break;
      case 0x610:
        Serial.println("7");
        break;
      case 0xE10:
        Serial.println("8");
        break;
      case 0x110:
        Serial.println("9");
        break;
      case 0x910:
        Serial.println("10");
        break;
      case 0x510:
        Serial.println("11");
        break;
      case 0xD10:
        Serial.println("12");
        break;
      case 0x12E9:
        Serial.println("青");
        break;
      case 0x52E9:
        Serial.println("赤");
        break;
      case 0x32E9:
        Serial.println("緑");
        break;
      case 0x72E9:
        Serial.println("黄");
        break;
      case 0x5D0:
        Serial.println("画面表示");
        break;
      case 0x1F58:
        Serial.println("NETFLIX");
        break;
      case 0x5923:
        Serial.println("ヘルプ");
        break;
      case 0x6923:
        Serial.println("視聴中メニュー");
        break;
      case 0x6D25:
        Serial.println("番組表");
        break;
      case 0x250:
        Serial.println("テレビ");
        break;
      case 0x2F0:
        Serial.println("↑");
        break;
      case 0xCD0:
        Serial.println("→");
        break;
      case 0x2D0:
        Serial.println("←");
        break;
      case 0xAF0:
        Serial.println("↓");
        break;
      case 0xA70:
        Serial.println("決定");
        break;
      case 0x70:
        Serial.println("ホーム");
        break;
      case 0x62E9:
        Serial.println("戻る");
        break;
      case 0x6758:
        Serial.println("番組チェック");
        break;
      case 0x490:
        Serial.println("音量+");
        break;
      case 0xC90:
        Serial.println("音量-");
        break;
      case 0x90:
        Serial.println("チャンネル+");
        break;
      case 0x890:
        Serial.println("チャンネル-");
        break;
      case 0x18E9:
        Serial.println("10キー");
        break;
      case 0x290:
        Serial.println("消音");
        break;
      case 0xE90:
        Serial.println("音声切り替え");
        break;
      case 0xAE9:
        Serial.println("字幕");
        break;
      case 0x5358:
        Serial.println("録画リスト");
        break;
      case 0x6CE9:
        Serial.println("早戻し");
        break;
      case 0x2CE9:
        Serial.println("再生");
        break;
      case 0x1CE9:
        Serial.println("早送り");
        break;
      case 0x1EE9:
        Serial.println("前");
        break;
      case 0x4CE9:
        Serial.println("一時停止");
        break;
      case 0x5EE9:
        Serial.println("次");
        break;
      case 0x2E9:
        Serial.println("録画");
        break;
      case 0xCE9:
        Serial.println("停止");
        break;
      case 0xD58:
        Serial.println("ブラビアリンク");
        break;
    }
    irrecv.resume();
  }
}
