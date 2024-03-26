
#include "console.h"
#include "tool.h"
#include "env.h"
#include <iostream>
#include <string>

namespace tool{

  // score의 길이를 검사하는 코드
  int numberLength(int number){
    if (number <= 0){
      return 0;
    }
    
      return 1 + numberLength(number/10); 
    
  }
  void drawScore(int score)
  {
    std::string scoreText = "Score: " + std::to_string(score * 10);
    console::draw(env::BOARD_SIZE / 2 - 4 - numberLength(score) /2, env::BOARD_SIZE, scoreText);
  }

  void drawResultMenu(bool isWin)
  {
    if (isWin)
    {
      console::draw(env::BOARD_SIZE / 2 - 4, env::BOARD_SIZE / 2-1, "YOU WIN!");
    }
    else
    {
      console::draw(env::BOARD_SIZE / 2 - 4, env::BOARD_SIZE / 2-1, "YOU LOSE!");
    }

    console::draw(env::BOARD_SIZE / 2 - 6, env::BOARD_SIZE / 2, "Try again? (Enter)");
  }


}