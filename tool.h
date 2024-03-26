#ifndef TOOL_H
#define TOOL_H

namespace tool{
// 프로그램에서 공통적으로 사용되는 좌표 구조체
struct coordinate {
  int x;
  int y;
};

// 기타 점수 화면 출력
void drawScore(int score);
// 기타 결과 화면 출력
void drawResultMenu(bool isWin);
};

#endif // TOOL_H
