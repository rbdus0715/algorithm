#include <iostream>
#define MAX 101
using namespace std;

int N, arr[MAX][MAX], dp_1[MAX][MAX], dp_2[MAX][MAX];

int d_1(int y, int x) {
    int& ret = dp_1[y][x];
    if(ret) return ret;
    if(y==N-1) return ret = arr[y][x];
    
    return ret = max(d_1(y+1, x), d_1(y+1, x+1)) + arr[y][x];
}

int d_2(int y, int x) {
    int& ret = dp_2[y][x];
    if(ret) return ret;
    
    if(y==N-1) return ret = 1;
    if(d_1(y+1, x) > d_1(y+1, x+1)) ret = d_2(y+1, x);
    else if(d_1(y+1, x) < d_1(y+1, x+1)) ret = d_2(y, x+1);
    else if(d_1(y+1, x) == d_1(y+1, x+1)) ret = d_2(y+1, x) + d_2(y+1, x+1);
    
    return ret;
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<=i; j++) {
            cin >> arr[i][j];
        }
    }
    d_1(0, 0);
    cout << d_2(0, 0);
}
