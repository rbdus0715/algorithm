#include <iostream>
#include <cmath>
using namespace std;

int n, w, work[1001][2], dp[1001][1001], result[1001];

int dist(int w1, int w2) {
    if(w1==0) return work[w2][0] + work[w2][1] - 2;
    else if(w2==0) return 2*n - work[w1][0] - work[w1][1];
    else return abs(work[w1][0]-work[w2][0]) + abs(work[w1][1]-work[w2][1]);
}

int d(int p1, int p2, int event) {
    if(p1==w || p2==w) return 0;
    
    int& ret = dp[p1][p2];
    if(ret) return ret;
    
    int police1 = d(event, p2, event+1)+dist(p1, event);
    int police2 = d(p1, event, event+1)+dist(event, p2);
    
    result[event] = min(result[event], min(police1, police2));
    
    ret = min(police1, police2);

    return ret;
}

void reconstruct(int p1, int p2) {
    if(p1==w || p2==w) return;
    
    int maxl = max(p1, p2) + 1;
    
    int police1 = dp[maxl][p2] + dist(p1, maxl);
    int police2 = dp[p1][maxl] + dist(maxl, p2);
    
    if(police1 < police2) {
        cout << 1 << endl;
        reconstruct(maxl, p2);
    }
    
    else {
        cout << 2 << endl;
        reconstruct(p1, maxl);
    }
}

int main() {
    cin >> n >> w;
    for(int i=1; i<=w; i++) 
        cin >> work[i][0] >> work[i][1];
    for(int i=1; i<=w; i++) result[i] = 2e9;
    
    cout << d(0, 0, 1) << endl;

    reconstruct(0, 0);
}
