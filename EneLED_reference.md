# EneLEDリファレンス

## void init(int board)
最初に呼び出すやつ。  
内容はSPIのセットアップ  
setup()の中で呼び出す  

## void led_xax(int color)
LEDの壁がx軸方向に進んでくる。  
デバッグ用のものを改変した。  
colorは0:RED,1:GREEN,2:BLUE  
1s刻み  

## void led_yax(int color)
xaxのy版  

## void led_zax(int color)
xaxのz版

## void led_test(int color)
LEDがひとつずつ光っていく。  
colorは0:RED,1:GREEN,2:BLUE  

## void led_clear()
LEDとGNDを全部OFFにする  

## void output()
LEDの出力をする。これを呼ばないと出力自体はされない  
タイマ割り込み等で入れておくと良き(ｵﾇﾇﾒは20Hzくらい)  

## void led_center()
3x3x3が真ん中で白色に光る  
センセに言われてる作った余興  