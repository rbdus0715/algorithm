#include <iostream>
using namespace std;

int G, S, N, dp[51];
string X{"X+YF"}, Y{"FX-Y"};

int cal_len(int gen) {
    dp[0] = 1;
    for(int i=1; i<=51; i++) {
        dp[i] = 2 * dp[i-1] + 2;
    }
}

char search(int gen, int skip, string curve) {
    if(gen==0) return curve[skip];
    
    for(int i=0; i<curve.size(); i++) {
        if(curve[i]=='X'||curve[i]=='Y') {
            if(skip>=dp[gen])
        }
    }
}

int main() {
    cin >> G >> S >> N;
    
}
