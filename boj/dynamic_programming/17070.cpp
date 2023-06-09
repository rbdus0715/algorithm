#include <iostream>
#include <vector>
using namespace std;

int N, map[17][17], dp[3][17][17];
// 각 파이프 방향별 움직임
vector<int> dx[3] = {
    {1, 1},
    {0, 1},
    {1, 0, 1}
};
vector<int> dy[3] = {
    {0, 1},
    {1, 1},
    {0, 1, 1}
};
// 움직인 후 파이프 방향
vector<int> after[3] = {
    {0, 2},
    {1, 2},
    {0, 1, 2}
};

bool canMove(int af, int m, int y, int x) {

    if(af!=2 && m!=1) return true;
    
    bool ans = true;
    for(int i=0; i<3; i++) {
        int ny = y + dy[2][i];
        int nx = x + dx[2][i];
        if(map[ny][nx]==1) ans=false;
    }
    return ans;
}

int d(int y, int x, int type) {
    if(y==N && x==N) {
        return 1;
    }
    
    int& ret = dp[type][y][x];
    if(ret != -1) return ret;
    
    ret=0;
    
    for(int i=0; i<dx[type].size(); i++) {
        int ny = y + dy[type][i];
        int nx = x + dx[type][i];
        if(ny<=N && nx<=N && canMove(after[type][i], map[ny][nx], y, x)) {
            ret += d(ny, nx, after[type][i]);
        }
    }
    
    return ret;
}

int main() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++){ 
            cin >> map[i][j];
            dp[0][i][j] = -1; dp[1][i][j] = -1; dp[2][i][j] = -1;
        }
    }
    cout << d(1, 2, 0);
}
