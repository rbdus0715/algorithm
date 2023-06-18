#include <iostream>
using namespace std;

int N, M, m[101], c[101], sum, dp[101][10001];

int main() {
    cin >> N >> M;
    for(int i=1; i<=N; i++) cin >> m[i];
    for(int i=1; i<=N; i++) { 
        cin >> c[i];
        sum += c[i];
    }
    
    for(int i=1; i<=N; i++) {
        for(int j=0; j<=sum; j++) {
            if(j>=c[i])
                dp[i][j] = dp[i-1][j-c[i]] + m[i];
            dp[i][j] = max(dp[i][j], dp[i-1][j]);
        }
    }
    
    for(int i=0; i<=sum; i++) {
        if(dp[N][i]>=M) {
            cout << i << endl;
            break;
        }
    }
}
