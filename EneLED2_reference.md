# EneLED2リファレンス
少し改良されて2になりました  
各段ごとに別のLEDを光らせられます  

## void init(int board)
初期化  
int boardはLEDキューブの基板番号(ただ処理は未実装)  

## void led_clear()
LEDの状態を全て消灯にする  

## void led_full(int color)
LEDの状態を全て点灯にする  
int colorは以下の通り  
| int color | 出力 | 色 |
| -------- | -------- | -------- |
| 0b000 | R:0,G:0,B:0 | 黒(消灯) |
| 0b001 | R:1,G:0,B:0 | 赤 |
| 0b010 | R:0,G:1,B:0 | 緑 |
| 0b011 | R:1,G:1,B:0 | 黄 |
| 0b100 | R:0,G:0,B:1 | 青 |
| 0b101 | R:1,G:0,B:1 | 紫 |
| 0b110 | R:0,G:1,B:1 | 水 |
| 0b111 | R:1,G:1,B:1 | 白 |
以下の色指定も全てこの通り。  

## void led_test()
対角に3色のLEDが一段ずつ下に下がる  
割り込みデバッグ用  

## void led_xaxis(int color)
指定した色でy-z平面のLEDの壁がx軸正方向に進む  

## void led_yaxis(int color)
指定した色でx-z平面のLEDの壁がy軸正方向に進む  

## void led_zaxis(int color)
指定した色でx-y平面のLEDの壁がz軸正方向に進む  

## void led_xaxis_rev(int color)
指定した色でy-z平面のLEDの壁がx軸逆方向に進む  

## void led_yaxis_rev(int color)
指定した色でx-z平面のLEDの壁がy軸逆方向に進む  

## void led_zaxis_rev(int color)
指定した色でx-y平面のLEDの壁がz軸逆方向に進む  

## void output()
LEDの出力を行う  
タイマ割り込みで500Hz前後で呼び出す  