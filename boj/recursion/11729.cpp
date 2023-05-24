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
#define MAX 10000000
using namespace std;

int N, cnt;
stack<int> tower[3];
int result[2][MAX];

void move(int n, int from, int to) {
    if(n==1){
        int top = tower[from].top();
        tower[from].pop();
        tower[to].push(top);
        if(N<20) {
            result[0][cnt] = from+1; result[1][cnt] = to+1;
        }
        cnt++;
        return;
    }
    
    int tempTo;
    for(int i=0; i<3; i++){
        if(i!=from && i!=to) tempTo = i;
    }
    
    move(n-1, from, tempTo);
    
    if(N<20){
        result[0][cnt] = from + 1; result[1][cnt] = to + 1;   
    }
    cnt++;
    
    int base = tower[from].top();
    tower[from].pop();
    tower[to].push(base);

    move(n-1, tempTo, to);
}

int main() {
    cin >> N;
    for(int i=N; i>0; i--){
        tower[0].push(i);
    }
    move(N, 0, 2);
    cout << cnt << '\n';
    if(N<=20){
        for(int i=0; i<cnt; i++){
            cout << result[0][i] << " " << result[1][i] << "\n";
        }
    }
}
