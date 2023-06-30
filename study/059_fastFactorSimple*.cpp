#include <iostream>
#include <cmath>
#include <vector>
using namespace std;
#define MAX_N 10000

int n, minFactor[MAX_N+1];

void eratosthenes2() {
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

vector<int> factor(int n) {
    vector<int> ret;
    
    while(n>1) {
        ret.push_back(minFactor[n]);
        n/=minFactor[n];
    }
    
    return ret;
}

int main() {
    cin >> n;
    eratosthenes2();
    vector<int> result = factor(n);
    for(int i:result) cout << i << " ";
}
