#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;
#define MAX 10000000

int n;
unsigned char sieve[(MAX+7)/8];

inline bool isPrime(int k) {
    // k >> 3 : k를 3으로 나눈다
    // k & 7 : k를 8로 나눈 나머지
    return sieve[k >> 3] & (1 << (k & 7));
}

inline void setNotPrime(int k) {
    sieve[k >> 3] &= ~(1 << k & 7);
}

void eratosthenes() {
    
    memset(sieve, 255, sizeof(sieve));
    
    setNotPrime(0);
    setNotPrime(1);
    
    int sqrtn = int(sqrt(n));
    for(int i=2; i<=sqrtn; i++) {
        if(isPrime(i))
            for(int j=i*i; j<=n; j+=i) setNotPrime(j);       
    }
}

int main() {
    cin >> n;
    eratosthenes();
    cout << isPrime(n);
}
