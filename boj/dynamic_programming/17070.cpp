#include <iostream>
using namespace std;

int N, map[17][17], dp[17][17];
const int dx[3] = {1, 1, 0};
const int dy[3] = {0, 1, 1};

// 1:가로, 2:세로, 3:대각선
bool canMove(int Type, iny y, int x) {
    if(Type==1 && x+1<=N) return true;
    if(Type==2 && y+1<=N) return true;
    if(Type==3 && (x+1<=N||y+1<=N)) return true;
    return false;
}

int d(int y, int x) {
    if(y==N && x==N) return 1;
    
    int& ret = dp[y][x];
    if(ret != -1) return ret;
    
    for(int i=1; i<=3; i++) {
        if(canMove(i, y, x)) // 여기까지 함
    }
}

int main() {
    cin >> N;
    for(int i=1; i<=N; i++) {
        for(int j=1; j<=N; j++){ 
            cin >> map[i][j];
            dp[i][j] = -1;
        }
    }
    cout << d(1, 2);
}
