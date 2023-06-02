#include <iostream>
#include <algorithm>
using namespace std;


int N, arr[1025][1025];
int dx[4]={0,1,0,1}, dy[4]={0,0,1,1};

int solve(int y, int x, int size) {
    
    if(size==1) return arr[y][x];
    
    int nextSize = size/2;
    
    int store[4];
    for(int i=0; i<4; i++) {
        store[i] = solve(y+dy[i]*nextSize, x+dx[i]*nextSize, nextSize);
    }
    sort(store, store+4);
    return store[2];
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) cin >> arr[i][j];
    }
    
    cout << solve(0, 0, N);
}
