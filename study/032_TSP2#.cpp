#include <iostream>
using namespace std;
#define MAX 16
#define INF 2e9

int N;
double a[MAX][MAX], dp[MAX][1<<MAX];

double d(int here, int visited) {
    if(visited==(1<<N)-1) return 0;
    
    double& ret = dp[here][visited];
    if(ret>0) return ret;
    ret = INF; // 최소화 문제이므로
    
    for(int next=0; next<N; next++) {
        if(visited & (1<<next)) continue;
        double ds = a[here][next] + d(next, visited + (1<<next));
        ret = min(ret, ds);
    }
    
    return ret;
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        for(int j=0; j<N; j++) cin >> a[i][j]; 
    }
    
    for(int i=0; i<N; i++) {
        for(int j=0; j<(1<<N); j++) dp[i][j] = -1;
    }
    
    double result=INF;
    for(int i=0; i<N; i++) {
        result = min(result, d(i, 1<<i));
    }
    cout << result;
}
