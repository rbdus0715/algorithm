#include <iostream>
#define MAX 101
using namespace std;

int N, map[MAX][MAX];
int dp[MAX][MAX];

bool solve(int y, int x) {
    if(y==N-1 && x==N-1) return true;
    if(dp[y][x]!=-1) return dp[y][x];
    if(y>=N||x>=N) return false;
    
    return dp[y][x] = solve(y+map[y][x], x) || solve(y, x+map[y][x]);
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    
    if(solve(0, 0)) cout << "YES";
    else cout << "NO";
}
