#include <iostream>
#include <cstring>
#define MAX 2001
using namespace std;

int N, s, e, a[MAX], dp[MAX][MAX], T;

bool d(int i, int j) {

    int& ret = dp[i][j];
    if(ret!=-1) return ret;
    
    if(i==j) return true;
    if(i+1==j && a[i+1]==a[j]) return true;
    
    if(a[i]!=a[j]) return ret = false;
    
    return ret = d(i+1, j-1);
}

int main() {
    ios::sync_with_stdio(false); cin.tie(0);

    cin >> N;
    for(int i=1; i<=N; i++) cin >> a[i];
    memset(dp, -1, sizeof(dp));
    cin >> T;
    while(T--) {
        cin >> s >> e;
        cout << d(s, e) << "\n";
    }
}
