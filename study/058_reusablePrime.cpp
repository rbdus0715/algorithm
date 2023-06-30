#include <iostream>
#include <vector>
#include <cmath>
#include <cstring>
using namespace std;
#define MAX_N 10000

// 정수 판별
bool isPrime(int n) {
    if(n<=1) return false;
    if(n==2) return true;
    if(n%2==0) return false;
    
    int sqrtn = int(sqrt(n));
    for(int i=3; i<=sqrtn; i+=2)
        if(n%i==0) return false;
    
    return true;
}

// 소인수 분해
vector<int> factorSimple(int n) {
    vector<int> ret;
    int sqrtn = int(sqrt(n));
    for(int i=2; i<sqrtn; i++) {
        while(n%i==0) {
            n/=i;
            ret.push_back(i);
        }
    }
    
    if(n>1) ret.push_back(n);
    return ret;
}

// 에라토스테네스의 체
int n;
bool isPrime_arr[MAX_N+1];
void eratosthenes() {
    
    memset(isPrime_arr, 1, sizeof(isPrime_arr));
    isPrime_arr[0] = isPrime_arr[1] = false;
    
    int sqrtn = int(sqrt(n));
    for(int i=2; i<=sqrtn; i++) {
        if(isPrime_arr[i])
            for(int j=i*i; j<=n; j+=i) 
                isPrime_arr[j] = false;
    }
}

int main() {
    
    // 13은 소수
    cout << isPrime(13) << endl;
    
    // 24의 소인수분해
    vector<int> a = factorSimple(24);
    for(int i:a) cout << i << " ";
    cout << endl;
    
    // 에라토스테네스의 체
    cout << "소수인지 판별하고 싶은 수를 입력하세요 : ";
    cin >> n;
    eratosthenes();
    cout << isPrime_arr[n] << endl;
    
}
