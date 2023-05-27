#include <iostream>
using namespace std;

int N, a[64][64];
const int dx[4] = {-1,0,-1,0};
const int dy[4] = {-1,-1,0,0};

int solve(int y, int x, int size) {
    
    if(size==1) {
        return a[i][j];
    }
    
    nextSize=size/2
    int sum{0}, cur[4];
    
    for(int i=0; i<4; i++) {
        dy = y + dy[i]*nextSize;
        dx = x + dx[i]*nextSize;
        cur[i] = solve(dy, dx, nextSize);
        sum += cur[i];
    }


}

int main() {
    cin >> N; 
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> a[i][j];
        }
    }
    
}
