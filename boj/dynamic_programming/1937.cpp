#include <iostream>
using namespace std;
#define MAX 501

int N, map[MAX][MAX], dp[MAX][MAX], res;
const int dx[4] = {0, 0, -1, 1};
const int dy[4] = {-1, 1, 0, 0};

int d(int y, int x) {
    // cout << y << " " << x << "\n";
    int& ret = dp[y][x];
    if(ret!=-1) return ret;
    
    ret = 0;
    for(int i=0; i<4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(ny>=0 && nx>=0 && ny<N && nx<N) {
            if(map[ny][nx] > map[y][x]) ret = max(ret, d(ny, nx) + 1);
        }
    }
    return ret;
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            res = max(res, d(i, j));
            //cout << res << "#\n";
        }
    }
    cout << res + 1;
}
