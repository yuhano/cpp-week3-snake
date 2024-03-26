# cpp-week3-snake

>  c++ 프로그래밍 3주차 과제

# 📖 Description

c++ 프로그래밍 3주차 과제입니다. 

외부 라이브러리를 이용하여 snake 게임 개발

## 🕰️ 개발 기간
* 24.03.21일 - 24.03.27일


## 💻 Getting Started

### 실방 방법
* snake
```
$ git clone https://github.com/yuhano/cpp-week3-snake.git snake
$ cd snake
$ g++ -Werror -std=c++11 -c *.cpp
$ g++ -o main.exe *.o
$ .\main.exe
```
### 화면 크기/속도 변경 방법
env.h
``` c++
namespace env
{
    const int BOARD_SIZE = 10; // 화면 크기 조정
    const int MOVE_DELAY = 15; // 속도 조절
}
```

console.h
``` c++
namespace console {

// 화면에 출력 가능한 최대 너비
const int SCREEN_WIDTH = 25;
// 화면에 출력 가능한 최대 높이
const int SCREEN_HEIGHT = 25;
    ...
}
```

## 🔧 Stack
- **Language**: c++ 

##  Project Structure

```markdown
cpp-week3
└── snake
    ├── apple.cpp // 사과 생성 및 그리는 기능
    ├── console.cpp // 게임 기능(외부 소스 코드)
    ├── env.h // 화면 크기, 속도 등 모든 코드에서 필요한 환경 변수를 저장
    ├── game.cpp // 전체적인 게임을 관리하는 기능
    ├── main.cpp // 메인함수
    ├── snake.cpp // 뱀을 그리는 기능
    ├── tool.cpp // 모든 코드에서 필요한 좌표 및 기타 기능
    └── wall.cpp // 벽을 그리는 기능 
```