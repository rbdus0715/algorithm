#include <iostream>
#include <cmath>
using namespace std;

// 수열의 빠른 합 1+2+...+N
// O(logN)
int sumArray(int n){
    if(n==1) return 1;
    if(n%2==1) return sumArray(n-1) + n;
    return 2*sumArray(n/2) + pow((n/2),2);
}

/*행렬의 거듭제곱
A^m = A^(m/2) * A^(m/2)
m이 홀수일 때 다음 두가지를 사용할 수 있다
1) A^m = A * A^(m-1)
2) A^m = A^(m/2) * A^(m/2+1)
문제마다 유리한 방법으로 풀면 된다.
행렬의 곱에서는 2번으로 하면 더 다양한 행렬곱 문제가 나와버리므로 좋지 않다.
*/

/*
분할 방식은 어떻게 분할 하느냐에 따라 시간 복잡도 차이가 커진다.
절반으로 나누는 알고리즘의 장점은 여러 번 계산이 중복되는 것을 막는 것이다.

병합 정렬 merge sort
퀵 정렬 quick sort
*/

// 카라츠바의 빠른 곱셈 알고리즘 : 두 큰 수를 곱하는 알고리즘
void normalize()

int main(){
    cout << sumArray(10);
}











