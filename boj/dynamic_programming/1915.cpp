#include <iostream>
using namespace std;

// O(n^2)인 것만 힌트 얻음

int N, M, a[1001][1001], dp[1001][1001], res; 

int main() {
    cin >> N >> M;
    for(int i=1; i<=N; i++) {
        string s;
        cin >> s;
        for(int j=1; j<=M; j++) {
            a[i][j] = s[j-1] - '0';
        }
    }
    
    //
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=M; j++) {
            if(a[i][j]==1) {
                dp[i][j] = min(min(dp[i-1][j], dp[i][j-1]) , dp[i-1][j-1]) + 1;
                res = max(res, dp[i][j]);
            }
        }
    }
    cout << res*res;
}
