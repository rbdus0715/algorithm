#include <iostream>
using namespace std;

int N, board[51], dp[51][51];

int d(int left, int right) {
    if(left>right) return 0;
    int& ret = dp[left][right];
    if(ret) return ret;
    
    ret = max(board[left] - d(left+1, right), board[right] - d(left, right-1));
    if(right-left+1>=2) {
        ret = max(ret, -d(left+2, right));
        ret = max(ret, -d(left, right-2));
    }
    
    return ret;
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) cin >> board[i];
    cout << d(0, N-1);
}
