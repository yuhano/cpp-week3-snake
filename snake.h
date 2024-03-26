#include "tool.h"

#ifndef SNAKE_H
#define SNAKE_H

namespace snake
{
    // snake 초기화 함수, 화면 크기 입력 시 뱀 위치가 정되는 array 반환
    tool::coordinate *init(int size);

    // 뱀 길이 늘리기
    void addSnake();
    // 뱀 그리기
    void drawSnake();
    // 뱀 이동하기, 하용용씩 값을 뒤로 이동한 다음, 첫번째에 머리 위치 저장.
    tool::coordinate moveSnake();
    // 뱀 머리의 화면 넘어감 방지용
    void restrictInScreen();

    // 화면 움직임의 방향을 입력 받으며 마지막으로 입력받은 값 저장.
    void handleInput();
    // 입력받은 위치가 비어 있는지 확인
    bool isEmpty(tool::coordinate coor);
    // 화면 크기 멋어남, 몸통 중복 발생, 등 뱀이 죽는 것을 감시
    bool isAlive(tool::coordinate coor_Head);
    // 뱀의 크기가 화면 크기를 넘어 이겼는지 확인.
    bool isWin();
    // 뱀의 현재 길이 출력
    int getScore();
}

#endif