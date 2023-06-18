#include <iostream>
#include <cstring>
using namespace std;
#define for(i, n) for(int i=0; i<n; i++)

int n, map[16][16], dp[16][1<<16];

int d(int start, int visited) {
    if(visited == (1<<n)-1) {
        if(map[start][0]>0)
            return map[start][0];
        else return 2e9;
    }
    
    int& ret = dp[start][visited];
    if(ret!=0) return ret;
    ret = 2e9;
    
    for(i, n) {
        if(visited & (1<<i)) continue;
        if(map[start][i]==0) continue;
        ret = min(ret, d(i, visited+(1<<i)) + map[start][i]);
    }
    
    return ret;
}

int main() {
    cin >> n;
    for(i, n) {
        for(j, n) cin >> map[i][j];
    }

    // ...00001
    int visited = 1;
    cout << d(0, visited);
}
