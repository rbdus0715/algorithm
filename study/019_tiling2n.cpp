#include <iostream>
using namespace std;

int N, dp[101];

int d(int n) {
    if(n<=1) return 1;
    int& ret = dp[n];
    if(ret) return ret;
    
    return ret = (d(n-1) + d(n-2)) % 1000000007;
}

int main() {
    cin >> N;
    cout << d(N);
}
