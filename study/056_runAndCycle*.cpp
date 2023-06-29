#include <iostream>
using namespace std;
#define MAX 10

int n, track;
double run[MAX], cycle[MAX];

double totalTime(int i, double r) {
    double c = track - r;
    return r/run[i] + c/cycle[i];
}

double diff(double r) {
    double cheater = totalTime(n-1, r);
    double other = totalTime(0, r);
    for(int i=1; i<n-1; i++) 
        other = min(other, totalTime(i, r));
    
    return other - cheater;
}

double solve() {
    double lo = 0, hi = track;
    for(int i=0; i<100; i++) {
        double a = (2*lo+hi)/3;
        double b = (lo+2*hi)/3;
        
        if(diff(a)>diff(b)) hi = b;
        else lo = a;
    }
    
    return (lo+hi) / 2;
}

int main() {
    cin >> track >> n;
    for(int i=0; i<n; i++) 
        cin >> run[i] >> cycle[i];
    
    cout << solve();
}
