#include <iostream>
#define MOD 1000000007
using namespace std;

int N, dp[101];

int d(int n) {
    if(n<=1) return 1;
    int& ret = dp[n];
    if(ret) return ret;
    
    return ret = (d(n-1) + d(n-2)) % MOD;
}

int tiling(int n) {
    if(n%2==1) return d(n/2);
    int ret = d(n);
  
    // <너무 큰 수라서 나머지 연산을 하는 문제에서 주의할 점>
    // 여기서 MOD로 나머지연산 하기 전에 MOD를 한 번 더해준다.
    // ret - d(n/2)가 음수일 수도 있기 때문이다.
    ret = (ret - d(n/2) + MOD) % MOD;
    ret = (ret - d(n/2-1) + MOD) % MOD;
    return ret;
}

int main() {
    cin >> N;
    cout << tiling(N);
}
