#include <iostream>
#define MOD 10000000
using namespace std;

int N, dp[101][101];

// 총 n개 블럭, 첫 번째 줄에 m개 블럭있음
int d(int n, int m) {
    if(n==0) return 1;

    int& ret = dp[n][m];
    if(ret) return ret;
    
    for(int i=1; i<=n; i++) {
        if(m==0) { 
            // 각 대입 혹은 덧셈 연산마다 숫자가 커질 것을 대비하여 나누기 연산을 끼워넣어야 함
            int add = d(n-i, i) % MOD;
            ret += add;
            ret %= MOD;
        }
        else {
            int add = (i+m-1)*d(n-i, i) % MOD;
            ret += add;
            ret %= MOD;
        }
    }

    return ret % MOD;
}

int main() {
    cin >> N;
    cout << d(N, 0);
}
