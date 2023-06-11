#include <iostream>
using namespace std;
#define INF 1000000000

int T, N, a[501], sum[501], dp[501][501];

int main() {
    cin >> T;
    
    while(T--) {
        cin >> N;
        for(int i=1; i<=N; i++) {
            cin >> a[i];
            sum[i] = sum[i-1] + a[i];
        }
        
        for(int i=1; i<=N; i++) {
            for(int j=1; j<=N-i; j++) {
                dp[j][i+j] = INF;
                for(int k=j; k<i+j; k++) {
                    dp[j][i+j] = min(dp[j][i+j], dp[j][k] + dp[k+1][i+j] + sum[i+j] - sum[j-1]);
                }
            }
        }
        
        cout << dp[1][N] << '\n';
    }
    
}
