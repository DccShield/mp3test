#include "DFRobotDFPlayerMini.h"
#include <SoftwareSerial.h>

unsigned long PreviosTime = 0;  // PreviosTime 前時間
int i = 1;
 
SoftwareSerial mySoftwareSerial(A4, A5); // RX, TX
DFRobotDFPlayerMini myDFPlayer;

void setup() {

  Serial.begin(115200);

  // ソフトウエアシリアル通信レートセット:
  mySoftwareSerial.begin(9600);

  myDFPlayer.begin(mySoftwareSerial);
  myDFPlayer.volume(10);  //Set volume value. From 0 to 30
 
  PreviosTime = millis();       // setup()終了時の時刻をPreviosTimeに格納
  myDFPlayer.play(i);
  i++;
}

void loop() {
  if( (millis() - PreviosTime ) >= 10000 ){  // 1000:1000msec 前回から1000ms経過したかチェック
   PreviosTime = millis();                 // 現在の時刻に更新
   myDFPlayer.play(i);
   Serial.println(i);
   i++;
   if(i>=10)
    i=1;
  }
}
