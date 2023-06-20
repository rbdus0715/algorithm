#include <iostream>
using namespace std;
#define MAX 1e9

int n, a[1001][3], dp[1001][3];

int d(int start) {
    for(int i=0; i<3; i++)
        if(i==start) dp[0][start] = a[0][start];
        else dp[0][i] = MAX;
    
    for(int i=1; i<n; i++) {
        for(int j=0; j<3; j++) {
            if(j==0) 
                dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + a[i][j];
            else if(j==1) 
                dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + a[i][j];
            else if(j==2) 
                dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + a[i][j];
        }
    }
    
    int ret = 2e9;
    for(int i=0; i<3; i++) 
        if(i!=start) ret = min(ret, dp[n-1][i]);
        
    return ret;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        for(int j=0; j<3; j++) 
            cin >> a[i][j];
    
    int result=2e9;
    for(int i=0; i<3; i++) result = min(result, d(i));
    cout << result;
}
