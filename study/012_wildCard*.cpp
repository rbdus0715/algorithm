#include <iostream>
#define MAX 101
using namespace std;

string P, S;
int dp[MAX][MAX];

bool d(int p, int s) {
    int& ret = dp[p][s];
    if(ret!=-1) return ret;
    
    while(p<P.size() && s<S.size() && (P[p]=='?'||P[p]==S[s])) {
        p++; s++;
    }
    
    if(p==P.size()) return ret = (s==S.size());
    
    if(P[p]=='*') {
        for(int i=s; i<S.size(); i++) {
            if(d(p+1, i)) return ret = 1;
        }
    }
    
    return ret = 0;
}

int main() {
    cin >> P >> S;
    
    int m = max(P.size(), S.size());
    for(int i=0; i<m; i++) {
        for(int j=0; j<m; j++) dp[i][j] = -1;
    }
    
    if(d(0, 0)) cout << "YES";
    else cout << "NO";  
}
