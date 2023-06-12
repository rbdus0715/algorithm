#include <iostream>
using namespace std;
#define MAX 1000001
#define MOD 1000000009

int T, N, dp[MAX];

int d(int n) {
    int& ret = dp[n];
    if(ret) return ret;
    
    return ret = ((d(n-1)%MOD + d(n-2)%MOD)%MOD + d(n-3)%MOD)%MOD;
}

int main() {
    cin >> T;
    
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    
    while(T--) {
        cin >> N;
        cout << d(N) << '\n';
    }
}
