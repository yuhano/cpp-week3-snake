#include "console.h"
#include "apple.h"
#include "snake.h"
#include "tool.h"
#include "wall.h"
#include "env.h"
#include <iostream>
#include <cstdlib>

using String = std::string;
using namespace tool;

coordinate coor_Direct{1, 0};

int moveCount = 0;
int score = 0;
coordinate *coor_Snakes;
coordinate coor_Head;

// 초기화에 필요한 함수
void init()
{
  // 콘솔 라이브러리를 초기화한다.
  console::init();
  wall::init(env::BOARD_SIZE);
  coor_Snakes = snake::init(env::BOARD_SIZE);
  apple::generateApple();
  score = 0;
}

// 각 화면 그리기
void draws()
{
  console::clear();
  wall::drawWall();
  snake::drawSnake();
  tool::drawScore(score);
  apple::drawApple();
}

void game()
{
  init();
  while (true)
  {
    // 화면을 지운다.
    snake::handleInput();
    snake::restrictInScreen();

    draws();

    // MOVE_DELAY가 일정 횟수가 되었을 때, 실행
    if (env::MOVE_DELAY == moveCount)
    {
      coor_Head = snake::moveSnake();
      moveCount = 0;
      if (!snake::isAlive(coor_Head))
      {
        draws();
        tool::drawResultMenu(false);
        console::wait();
        break;
      }
    }

    moveCount++;

    // 사과를 먹었을 경우
    if (apple::checkEatApple(coor_Head))
    {
      apple::generateApple();
      snake::addSnake();

      score = snake::getScore();

      if(snake::isWin()){
        draws();
        tool::drawResultMenu(true);
        console::wait();
        break;       
      }
    }

    // 게임 중간에 사용자가 중지한 경우의 입력
    if (console::key(console::K_ESC))
    {
      exit(0);
    }

    // 화면을 갱신하고 다음 프레임까지 대기한다.
    console::wait();
  }

  // 다시시작 메뉴 재실행
  while (true)
  {
    if (console::key(console::K_ESC))
    {
      exit(0);
    }
    if (console::key(console::K_ENTER))
    {
      game();
    }
    console::wait();
  }
}
