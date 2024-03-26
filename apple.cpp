#include "console.h"
#include "tool.h"
#include "apple.h"
#include "snake.h"
#include "env.h"

using tool::coordinate;

namespace apple{

bool isNewApple = true;
coordinate coor_Apple {5,5};
coordinate * coor_Snake;

void init(coordinate * Snakes){
  coor_Snake = Snakes;
}

void generateApple(){
  if(isNewApple){
    coor_Apple = {(int)rand()%(env::BOARD_SIZE-2) + 1, (int)rand()%(env::BOARD_SIZE-2) +1};
    if (!snake::isEmpty(coor_Apple)){
      generateApple();
    }
    else{
      isNewApple = false;
    }
  }
}

void drawApple(){
  console::draw(coor_Apple.x, coor_Apple.y, APPLE_STRING);
}

bool checkEatApple(tool::coordinate coor_Head){
  if(coor_Head.x == coor_Apple.x && coor_Head.y == coor_Apple.y){
    isNewApple = true;
    return true;
  }
  else{
    return false;
  }
}

}