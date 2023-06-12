#include <iostream>
using namespace std;

int N, dp[50001];

int d(int n, int m) {
    if(dp[n]==1 && m<=4) return 1;
    
    int& ret = dp[n];
    if(ret) return ret;
    
    ret = 2e9;
    for(int i=1; i*i<n; i++) {
        ret = min(ret, d(n-i*i, m+1)+1);
    }
    return ret;
}

int main() {
    cin >> N;
    for(int i=1; i*i<=50000; i++) {
        dp[i*i] = 1;
    }
    cout << d(N, 1);
}
