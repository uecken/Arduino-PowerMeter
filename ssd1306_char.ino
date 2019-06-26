// https://qiita.com/takahiro_itazuri/items/d7bc7331b196921b5880

#include<Wire.h>
#include<Adafruit_GFX.h>
#include<Adafruit_SSD1306.h>

// ディスプレイ変数の宣言
Adafruit_SSD1306 display(-1);

void setup() {
  // ディスプレイの初期化
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
}

void loop() {
  // ディスプレイをクリア
  display.clearDisplay();

  // 出力する文字の大きさ
  display.setTextSize(2);
  // 出力する文字の色
  display.setTextColor(WHITE);
  // 文字の一番端の位置
  display.setCursor(0, 0);

  // 出力する文字列
  display.println("LogDetect");
  display.println("AD8317");
  display.print((analogRead(0)*5.0/1023.0)); //
  display.println("  V");
  display.print((analogRead(0)*5.0/1023.0 - 0.35)/0.022);
  display.println(" dBm");
 
  // ディスプレイへの表示
  display.display();
  // 1000msec待つ
  delay(100);
}
