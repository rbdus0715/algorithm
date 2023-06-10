#include <iostream>
#define MAX 2001
using namespace std;

int N, a[MAX], dp[MAX][MAX], T, s, e;

int main() {
    ios::sync_with_stdio(false); cin.tie(0);
    
    cin >> N;
    for(int i=1; i<=N; i++) { 
        cin >> a[i];
        dp[i][i] = 1;
    }
    for(int i=1; i<N; i++) {
        if(a[i]==a[i+1]) dp[i][i+1] = 1;
    }
    
    for(int i=N; i>=1; i--) {
        for(int j=i+2; j<=N; j++) {
            if(a[i]==a[j] && dp[i+1][j-1]==1) dp[i][j] = 1;
        }
    }
    
    cin >> T;
    while(T--) {
        cin >> s >> e;
        cout << dp[s][e] << '\n';
    }
}
