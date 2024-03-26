#include <iostream>
#include "console.h"
using String = std::string;

#ifndef WALL_H
#define WALL_H

// 화면 그리는 과정에서 필요한 char 값
#define WALL_VERTICAL_STRING "┃"
#define WALL_HORIZONTAL_STRING "━"
#define WALL_RIGHT_TOP_STRING "┓"
#define WALL_LEFT_TOP_STRING "┏"
#define WALL_RIGHT_BOTTOM_STRING "┛"
#define WALL_LEFT_BOTTOM_STRING "┗"

namespace wall
{
    // 화면 크기 초기화
    void init(int size);
    // 화면 그리기
    void drawWall();

};

#endif