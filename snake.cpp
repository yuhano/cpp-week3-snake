#include "console.h"
#include "tool.h"
#include "env.h"
#include <iostream>
#include <String>

#define SNAKE_STRING "■"
#define SNAKE_BODY_STRING "■"

using tool::coordinate;

namespace snake
{
  int wallSize;
  int snakeSize = 1;
  int snakeLength;
  coordinate *coor_Snake;
  coordinate coor_Head;
  coordinate coor_Direct;

  coordinate *init(int size)
  {
    coor_Head = {(int)env::BOARD_SIZE / 2, (int)env::BOARD_SIZE / 2};
    coor_Direct = {1, 0};
    wallSize = size;
    snakeLength = (wallSize - 2) * (wallSize - 2);
    coor_Snake = new coordinate[snakeLength];
    coor_Snake[0] = {coor_Head.x, coor_Head.y};
    snakeSize = 1;
    return coor_Snake;
  }

  void addSnake()
  {
    snakeSize++;
  }

  void restrictInScreen()
  {
    // x, y 위치를 화면의 최대 크기에서 벗어나지 않게 한다.
    if (coor_Head.x < 0)
      coor_Head.x = 0;
    if (coor_Head.x >= console::SCREEN_WIDTH)
      coor_Head.x = console::SCREEN_WIDTH - 1;
    if (coor_Head.y < 0)
      coor_Head.y = 0;
    if (coor_Head.y >= console::SCREEN_HEIGHT)
      coor_Head.y = console::SCREEN_HEIGHT - 1;
  }

  void handleInput()
  {
    if (coor_Direct.x != 1 && console::key(console::K_LEFT))
    {
      coor_Direct.x = -1;
      coor_Direct.y = 0;
    }
    if (coor_Direct.x != -1 && console::key(console::K_RIGHT))
    {
      coor_Direct.x = +1;
      coor_Direct.y = 0;
    }
    if (coor_Direct.y != 1 && console::key(console::K_UP))
    {
      coor_Direct.x = 0;
      coor_Direct.y = -1;
    }
    if (coor_Direct.y != -1 && console::key(console::K_DOWN))
    {
      coor_Direct.x = 0;
      coor_Direct.y = +1;
    }
  }

  void drawSnake()
  {
    for (int i = 0; i < snakeSize; i++)
    {
      console::draw(coor_Snake[i].x, coor_Snake[i].y, SNAKE_BODY_STRING);
    }
  }

  coordinate moveSnake()
  {
    for (int i = 0; i < snakeSize; i++)
    {
      coor_Snake[snakeSize - i] = {coor_Snake[snakeSize - i - 1].x, coor_Snake[snakeSize - i - 1].y};
    }
    coor_Head = {coor_Head.x + coor_Direct.x, coor_Head.y + coor_Direct.y};
    coor_Snake[0] = {coor_Head.x, coor_Head.y};
    return coordinate{coor_Snake[0].x, coor_Snake[0].y};
  }

  bool isEmpty(coordinate coor)
  {
    for (int i = 1; i < snakeSize; i++)
    {
      if (coor.x == coor_Snake[i].x && coor.y == coor_Snake[i].y)
      {
        return false;
      }
    }
    return true;
  }

  bool isAlive(coordinate coor_Tmp)
  {
    if (coor_Tmp.x == 0 || coor_Tmp.x == wallSize - 1)
    {
      return false;
    }
    if (coor_Tmp.y == 0 || coor_Tmp.y == wallSize - 1)
    {
      return false;
    }
    if (!isEmpty(coor_Head))
    {
      return false;
    }
    return true;
  }

  bool isWin()
  {
    if (snakeSize == snakeLength)
    {
      return true;
    }
    else
    {
      return false;
    }
  }

  int getScore()
  {
    return snakeSize - 1;
  }

}