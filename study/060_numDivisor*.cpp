#include <iostream>
#include <cmath>
using namespace std;
#define MAX 1000000

int n, minFactor[MAX+1], minFactorPower[MAX+1], numDivisor[MAX+1];

void eratosthenes() {
    minFactor[0] = minFactor[1] = -1;
    
    for(int i=2; i<=n; i++) 
        minFactor[i] = i;
    
    int sqrtn = int(sqrt(n));
    for(int i=2; i<=sqrtn; i++) {
        if(minFactor[i]==i) {
            for(int j=i*i; j<=n; j+=i)
                if(minFactor[j]==j) minFactor[j] = i;
        }
    }
}

void solve() {
    numDivisor[1] = 1;
    for(int i=2; i<=n; i++) {
        // 소수인 경우
        if(minFactor[i]==i) {
            minFactorPower[i] = 1;
            numDivisor[i] = 2;
        }
        
        // 소수가 아닌 경우
        else {
            int p = minFactor[i];
            int m = i/p;
            if(minFactor[m] != p)
                minFactorPower[i] = 1;
            else
                minFactorPower[i] = minFactorPower[m] + 1;
            int a = minFactorPower[i];
            numDivisor[i] = (numDivisor[m]/a) * (a+1);
        }
    }
}


int main() {
    cin >> n;
    eratosthenes();
    solve();
    cout << numDivisor[n];
}
