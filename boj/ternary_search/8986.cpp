#include <iostream>
#include <cmath>
using namespace std;
#define ll long long

int n;
ll location[100001];

ll f(ll x) {
    ll ret = 0;
    for(int i=1; i<n; i++) {
        ret += abs(location[i]-i*x);
    }
    return ret;
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> location[i];
    
    if(n==1) {
        cout << "0";
        return 0;
    }
    
    ll lo = 1, hi = location[n-1];
    while(lo+3<=hi) {
        ll a = (2*lo+hi)/3;
        ll b = (lo+2*hi)/3;
        if(f(a)<=f(b)) hi = b;
        else lo = a;
    }
    
    ll res = 100000000000000;
    for(ll i=lo; i<=hi; i++) res = min(res, f(i));
    cout << res;
}
