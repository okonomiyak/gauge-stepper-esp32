#include <Arduino.h>

#define IN1 14  // 緑
#define IN2 13  // 茶
#define IN3 27  // 青
#define IN4 12  // 赤
#define BUTTON 26

// 4相励磁順(フルステップ)
int seq[4][4] = {
  {1,0,0,0},
  {0,1,0,0},
  {0,0,1,0},
  {0,0,0,1}
};

void setup() {
  pinMode(IN1, OUTPUT);
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
  pinMode(BUTTON, INPUT_PULLUP); // ボタンの片側をGPIO、もう片側をGNDに繋ぐだけでOK
}

void loop() {
  bool reverse = (digitalRead(BUTTON) == LOW); // 押されたらLOWになる

  if (reverse) {
    for (int s = 3; s >= 0; s--) {
      digitalWrite(IN1, seq[s][0]);
      digitalWrite(IN2, seq[s][1]);
      digitalWrite(IN3, seq[s][2]);
      digitalWrite(IN4, seq[s][3]);
      delay(10);
    }
  } else {
    for (int s = 0; s < 4; s++) {
      digitalWrite(IN1, seq[s][0]);
      digitalWrite(IN2, seq[s][1]);
      digitalWrite(IN3, seq[s][2]);
      digitalWrite(IN4, seq[s][3]);
      delay(10);
    }
  }
}