/* 信号読むようのプログラム
 * 恐らくパナソニック非対応?
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
    Serial.println(results.value, HEX);
    irrecv.resume();
  }
}
