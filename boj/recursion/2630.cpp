#include <iostream>
using namespace std;

int N, cnt_W, cnt_B, arr[128][128];

void solve(int y, int x, int size) {
    if(size==1) {
        if(arr[y][x]) cnt_B++;
        else cnt_W++;
        return;
    }
    
    bool all_0{true}, all_1{true};
    for(int i=y; i<y+size; i++) {
        for(int j=x; j<x+size; j++) {
            if(arr[i][j]==1) all_0 = false;
            if(arr[i][j]==0) all_1 = false;
        }
    }
    
    if(all_0) {
        cnt_W++;
        return;
    }
        
    if(all_1) {
        cnt_B++;
        return;
    }
    
    solve(y, x, size/2);
    solve(y, x+size/2, size/2);
    solve(y+size/2, x, size/2);
    solve(y+size/2, x+size/2, size/2);
    
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) {
            cin >> arr[i][j];
        }
    }
    solve(0, 0, N);
    cout << cnt_W << "\n" << cnt_B;
}
