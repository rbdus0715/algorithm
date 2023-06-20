#include <iostream>
#include <cstring>
using namespace std;

int t, n, m, cost[21], dp[10001];

int main() {
    cin >> t;
    while(t--) {
        cin >> n;
        for(int i=1; i<=n; i++) cin >> cost[i];
        cin >> m;
        dp[0] = 1;
        for(int i=1; i<=n; i++) {
            for(int j=cost[i]; j<=m; j++) {
                dp[j] = dp[j] + dp[j-cost[i]];
            }
        }
        cout << dp[m] << '\n';
        memset(dp, 0, sizeof(dp));
    }
}
