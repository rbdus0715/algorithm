#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> M;
int cntX, cntO, dp[19683];
char state{'o'};

bool finished(vector<string> m, char turn) {
    
    for(int i=0; i<3; i++) {
        int same1{0}, same2{0};
        for(int j=0; j<3; j++) {
            if(m[i][j]==turn) same1++;
            if(m[j][i]==turn) same2++;
        }
        if(same1==3 || same2==3) {
            return true;
        }
    }
    return false;
}

// 3진법으로 표현
int toTernary(vector<string> m) {
    int ret{0};
    
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            ret *= 3;
            if(m[i][j]=='o') ret++;
            else if(m[i][j]=='x') ret += 2;
        }
    } 
    
    return ret;
}

int canWin(vector<string> m, char turn) {
    if(finished(m, 'o'+'x'-turn)) return -1; 
    
    int& ret = dp[toTernary(m)];
    if(ret!=-2) return ret;
    
    int minVal = 2;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(m[i][j]=='.') {
                m[i][j] = turn;
                minVal = min(minVal, canWin(m, 'o'+'x'-turn));
                m[i][j] = '.';
            }
        }
    }
    
    if(minVal==2 || minVal==0) return ret = 0;
    return ret = -minVal;
}

int main() {
    for(int i=0; i<3; i++) {
        string a;
        cin >> a;
        for(int j=0; j<3; j++) {
            if(a[j]=='x') cntX++;
            else if(a[j]=='o') cntO++;
        }
        M.push_back(a);
    }
    fill(dp, dp+19683, -2);
    
    if(cntX==cntO) state = 'x';

    int result = canWin(M, state);
    
    if(result==1) {
        if(state=='x') cout << 'x';
        else cout << 'o';
    }
    else if(result==-1) {
        if(state=='x') cout << 'o';
        else cout << 'x';
    }
    else cout << "TIE";
}
