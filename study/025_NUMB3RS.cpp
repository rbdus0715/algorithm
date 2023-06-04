#include <iostream>
#include <vector>
using namespace std;

int N, D, P, dp[101][51];
vector<int> map[51];

int d(int day, int location) {
    if(day==D) return 1;
    
    for(int i:map[location]) {
        
        int& ret = dp[day+1][i];
        if(ret!=-1) return ret;
        
        if(i!=P) {
            ret =  
        }
    }
    
}

int main() {
    cin >> N >> D >> P;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) map[i].push(back);
    }
    for(int i=0; i<D; i++) memset(dp[i], -1, sizeof(dp[i]));
    
    d(0, P);
    
    int t; cin >> t; while(t--) {
        int x; cin >> x; cout << dp[0][x];
    }
}
