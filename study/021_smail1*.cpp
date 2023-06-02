#include <iostream>
using namespace std;

// N: 우물의 깊이, M: 장마 기간의 길이
int N, M, dp[2*1001][1001];

int d(int depth, int days) {
    if(days==M) return depth>=N?1:0;
    
    int& ret = dp[depth][days];
    if(ret!=-1) return ret;
    
    return ret = d(depth+1, days+1) + d(depth+2, days+1);
}

int main() {
    cin >> N >> M;
    for(int i=0; i<=2*N+1; i++) {
        for(int j=0; j<=M; j++) {
            dp[i][j] = -1;
        }
    }
    
    cout << d(0, 0);
}
