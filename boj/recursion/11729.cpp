// 하노이탑
// n층을 옮기기 위해서는 그 위의 n-1층을 먼저 빼놔야 한다
/*
예시
위의 4층을 옮기기 위해서는
그 위의 3단을 3번으로 옮기고,
4번째 층을 2번으로 옮긴 후,
위와 같은 메커니즘을 사용하여 3단을 다시 2번으로 옮긴다.

풀이:
위에서부터 n층을 2번으로 위칙로 옮기는 함수

x = 2
move(int n, int x){
  ...
  
  x가 2 -> to는 3;
  x가 3 -> to는 2;
  
  (1) move(int n-1, int to);
  (2) n층을 2번으로 옮긴다
  (3) move(int n-1, int x); 
}

*/

// 하노이탑 : stack 자료구조 필요

#include <iostream>
#include <stack>
using namespace std;

int N;

void

int mian() {
    cin >> N;
    move(N, 3);
}
