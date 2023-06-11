#include <iostream>
using namespace std;
#define MAX 1001

int dp[MAX][MAX];
string a, b;

void print(int i, int j) {
    if(dp[i][j]==0) return;
    if(a[i-1]==b[j-1]) {
        print(i-1, j-1);
        cout << a[i-1];
    }
    else dp[i-1][j]>dp[i][j-1] ? print(i-1, j) : print(i, j-1); 
}

int main() {
    cin >> a >> b;
    for(int i=0; i<a.size(); i++) {
        for(int j=0; j<b.size(); j++) {
            if(a[i]==b[j]) dp[i+1][j+1] = dp[i][j] + 1;
            else dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j]);
        }
    }
    cout << dp[a.size()][b.size()] << "\n";
    print(a.size(), b.size());
}

