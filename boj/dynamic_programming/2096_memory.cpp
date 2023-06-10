#include <iostream>
#include <cstring>
#define MAX 100001
using namespace std;

int N, a[MAX][3], dp[MAX][3];

int d_max(int n, int i) {
    if(i==-1 || i==3) return 0;
    if(n==N) return a[n][i];
    
    int& ret = dp[n][i];
    if(ret != -1) return ret;
    
    ret = 0;
    for(int j=-1; j<=1; j++) {
        ret = max(ret, d_max(n+1, i+j)+a[n][i]);
    }
    return ret;
}

int d_min(int n, int i) {
    if(i==-1 || i==3) return 2e9;
    if(n==N) return a[n][i];
    
    int& ret = dp[n][i];
    if(ret != -1) return ret;
    
    ret = 2e9;
    for(int j=-1; j<=1; j++) {
        ret = min(ret, d_min(n+1, i+j)+a[n][i]);
    }
    return ret;
}

int main() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=0; j<3; j++) cin >> a[i][j]; 
    }
    
    memset(dp, -1, sizeof(dp));
    cout << d_max(0, 1) << " ";
    memset(dp, -1, sizeof(dp));
    cout << d_min(0, 1);
}
