#include <iostream>
using namespace std;

void move(int n, int from, int to, int pass){
    if(n==1) {
        cout << from << " " << to << "\n";
        return;
    }
    
    move(n-1, from, pass, to);
    cout << from << " " << to << "\n";
    move(n-1, pass, to, from);
}

int main(){
    int N; cin >> N;
    cout << (1<<N)-1 << "\n";
    move(N, 1, 3, 2);
}

/*
저번 풀이에서 개선된 점들
1) 스택 자료구조를 괜히 사용해서 그 과정을 구현하려고 했다. 재귀 함수를 잘 분석했다면 필요가 없었음을 알 수 있다.
2) 총 이동 개수를 수학적인 방법을 이용해서 O(1) 시간에 구한 것
  An+1 = 2*An + 1
  A1 = 1
  두 식을 잘 이용해서 An = 2^n - 1이라는 결론을 얻음
*/
