#include <iostream>
#include <iomanip>
using namespace std;

double N, R;
int M;

double balance(double amount, int duration, double rates, double monthPayment) {
    
    double ret = amount;
    
    for(int i=0; i<duration; i++) {
        ret = ret * (1 + (rates/12.0)/100.0);
        ret -= monthPayment;
    }
    
    return ret;
}

double pay(double amount, int duration, double rates) {
    
    double lo = 0, hi = amount * (1 + (rates/12.0)/100.0);
    
    for(int i=0; i<100; i++) {
        double mid = (lo+hi) / 2;
        double fmid = balance(amount, duration, rates, mid);
        if(fmid>0) lo = mid;
        else hi = mid;
    }
    
    return (lo+hi) / 2;
}

int main() {
    cin >> N >> M >> R;
    cout << setprecision(12) << pay(N, M, R);
}
