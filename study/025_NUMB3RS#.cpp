#include <iostream>
#include <vector>
using namespace std;

// 두니발 박사 탈옥 문제
// 1. 두니발 박사는 산길로만 이동
// 2. 교도소를 탈출한 당일, 교도소와 인접한 마을 하나로 도망쳐 은신

// 3. 두니발 박사는 수색을 피하기 위해 매일 인접한 마을로 움직여 피신
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
