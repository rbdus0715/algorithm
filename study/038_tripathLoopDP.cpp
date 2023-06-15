#include <iostream>
using namespace std;

// 반복적 동적 계획법
int n, map[101][101], dp[101][101];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) cin >> map[i][j];
    }
    
    for(int i=0; i<n; i++)
        dp[n-1][i] = map[n-1][i];
    
    for(int i=n-2; i>=0; i--)
        for(int j=0; j<=i; j++)
            dp[i][j] = map[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
            
    cout << dp[0][0];
}

// 슬라이딩 윈도
int n, map[101][101], dp[2][101];

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        for(int j=0; j<=i; j++) cin >> map[i][j];
    }
    
    for(int i=0; i<n; i++)
        dp[(n-1)%2][i] = map[n-1][i];
    
    for(int i=n-2; i>=0; i--)
        for(int j=0; j<=i; j++)
            dp[i%2][j] = map[i][j] + max(dp[(i+1)%2][j], dp[(i+1)%2][j+1]); 
    
    cout << dp[0][0];   
}
