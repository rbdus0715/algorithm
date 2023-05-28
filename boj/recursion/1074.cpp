#include <iostream>
#include <cmath>
using namespace std;

/*
첫 번째 풀이
int N, r, c, arr[32768][32768], cnt;
void solve(int y, int x, int size) {
    if(size==1) {
        arr[y][x] = cnt++;
        return;
    }
    
    solve(y, x, size/2);
    solve(y, x+size/2, size/2);
    solve(y+size/2, x, size/2);
    solve(y+size/2, x+size/2, size/2);
}
int main() {
    cin >> N >> r >> c;
    solve(0, 0, pow(2, N));
    cout << arr[r][c];
}
->> 단점 : 메모리를 너무 잡아먹음
*/

#include <iostream>
#include <cmath>
using namespace std;

int N, R, C;

void solve(int cur, int size) {
    
    if(size==1) {
        cout << cur;
        return;
    }
    
    int nextSize=size/2;
    int y = (R%size)/nextSize;
    int x = (C%size)/nextSize;
    
    if(y==0) {
        if(x==0) solve(cur, nextSize);
        else if(x==1) solve(cur+pow(nextSize, 2), nextSize);
    }
    else if(y==1) {
        if(x==0) solve(cur+2*pow(nextSize, 2), nextSize);
        else if(x==1) solve(cur+3*pow(nextSize, 2), nextSize);
    }

}

int main() {
    cin >> N >> R >> C;
    solve(0, pow(2, N));
}

