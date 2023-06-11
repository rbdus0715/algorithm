#include <iostream>
using namespace std;
#define MAX 1000001

int N, dp[MAX], before[MAX], idx;

int main() {
    cin >> N;
    
    for(int i=2; i<=N; i++) {
        dp[i] = dp[i-1] + 1;
        before[i] = i-1;
        
        if(i%2==0 && dp[i] > dp[i/2] + 1) {
            dp[i] = dp[i/2] + 1;
            before[i] = i/2;
        }
        
        if(i%3==0 && dp[i] > dp[i/3] + 1) {
            dp[i] = dp[i/3] + 1;
            before[i] = i/3;
        }
    }
    
    cout << dp[N] << '\n';
    idx = N;
    while(idx != 0) {
        cout << idx << " ";
        idx = before[idx];
    }
}
