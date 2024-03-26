# 코드에서 사용된 문법 정리

## struct

변수들을 하나로 묶어 새로운 변수로 정의

### struct 선언 맟 정의

``` c++
struct coordinate {
  int x;
  int y;
};
```

``` c++
coordinate coor1; // 선언
coor1.x = 10;
coor1.y = 20;

coordiante coor2 = {5, 10};

coordinate coor3 {2, 4};
```

## 파일 불러오기

### h 파일 불러오기

``` c++
#include "tool.h"
```

### using 사용하기
``` c++
using tool;
using tool::coordiate;
```

### h 파일 정의하기
``` c++
#ifndef APPLE_H
#define APPLE_H 
    함수 선언
#endif
```
이때 파일명은 대문자로,마침표는 언더바_로 치환합니다. 

ifndef는 if not define 이고 def는 아시다시피 define의 약자로 이를 합쳐 선언되어 있지 않다면 위와 같이 선언하라는 뜻입니다.