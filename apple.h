
#include "tool.h"

#ifndef APPLE_H
#define APPLE_H
#define APPLE_STRING "●"

using tool::coordinate;

namespace apple
{
    // 초기화 함수, 뱀 몸통의 좌표가 저장되어 있는 함수를 매개변수로 입력
    void init(coordinate *Snakes);
    // 사과 생성
    void generateApple();
    // 사과 그리기
    void drawApple();
    // 사과 먹었는지 확인
    bool checkEatApple(tool::coordinate coor_Head);
}
#endif