#include <iostream>
#include "console.h"
#include "wall.h"

using String = std::string;

namespace wall
{

  String wallTopString;
  String wallMiddleString;
  String wallBottomString;
  int wallSize;

  // 초기화 시 게임 내에서 지속적으로 필요한 string 값 생성 함수
  String generateWallString(int size, String startChar, String middleChar, String endChar)
  {
    String tmpString = "";
    for (int i = 0; i < size; i++)
    {
      if (i == 0)
      {
        tmpString.append(startChar);
      }
      else if (i == size - 1)
      {
        tmpString.append(endChar);
      }
      else
      {
        tmpString.append(middleChar);
      }
    }
    return tmpString;
  }

  void init(int size)
  {
    wallSize = size;
    wallTopString = generateWallString(wallSize, WALL_LEFT_TOP_STRING, WALL_HORIZONTAL_STRING, WALL_RIGHT_TOP_STRING);
    wallMiddleString = generateWallString(wallSize, WALL_VERTICAL_STRING, " ", WALL_VERTICAL_STRING);
    wallBottomString = generateWallString(wallSize, WALL_LEFT_BOTTOM_STRING, WALL_HORIZONTAL_STRING, WALL_RIGHT_BOTTOM_STRING);
  }

  void drawWall()
  {
    console::draw(0, 0, wallTopString);
    for (int i = 1; i < wallSize - 1; i++)
    {
      console::draw(0, i, wallMiddleString);
    }
    console::draw(0, wallSize - 1, wallBottomString);
  }
}