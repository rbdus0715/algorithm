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

/*
7
2 5 1 6 1 4 1
6 1 1 2 2 9 3
7 2 3 2 1 3 1
1 1 3 1 7 1 2
4 1 2 3 4 1 2
3 3 1 2 3 4 1
1 5 2 9 4 7 0

7
2 5 1 6 1 4 1
6 1 1 2 2 9 3
7 2 3 2 1 3 1
1 1 3 1 7 1 2
4 1 2 3 4 1 3
3 3 1 2 3 4 1
1 5 2 9 4 7 0 
*/
