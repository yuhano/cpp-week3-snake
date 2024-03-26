void game();
#include <ctime>
#include <cstdlib>

int main (){
    srand((unsigned int)time(NULL));        // 랜덤 seed 생성
    game();
    return 0;
}