#include <iostream>
#include <cmath>
using namespace std;
#define MAX 2000000000
#define ll long long

ll N, M;

ll winRate(ll play, ll win) {
    return (win*100)/play;
}

ll solve(ll play, ll win) {
    
    if(winRate(play, win)==winRate(play+MAX, win+MAX)) return -1;
    
    ll lo = 0, hi = MAX;
    ll rate = winRate(play, win);
    
    while(lo + 1 < hi) {
        ll mid = (lo + hi) / 2;
        ll fmid = winRate(play+mid, win+mid);
        if(fmid==rate) lo = mid;
        else hi = mid;
    }
    
    return hi;
}

int main() {
    cin >> N >> M;
    cout << solve(N, M);
}
