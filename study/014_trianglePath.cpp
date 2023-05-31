#include <iostream>
#define MAX 101
using namespace std;

int N, arr[MAX][MAX], dp[MAX][MAX];

int d(int y, int x) {
    int& ret = dp[y][x];
    if(ret) return ret;
    if(y==N-1) return ret = arr[y][x];
    
    return ret = max(d(y+1, x), d(y+1, x+1)) + arr[y][x];
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<=i; j++) {
            cin >> arr[i][j];
        }
    }
    cout << d(0, 0);
}
