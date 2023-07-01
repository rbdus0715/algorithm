#include <iostream>
#include <vector>
using namespace std;
#define MAX 100001
#define ll long long
#define MOD 20091101

int n, k, arr[MAX];
ll psum[MAX];

int ways() {
    
    int ret = 0;
    
    vector<ll> count(k, 0);
    for(int i=1; i<=n; i++)
        count[psum[i]]++;
    
    // k로 나눈 나머지이므로 0부터 k까지 순회한다
    for(int i=0; i<k; i++)
        if(count[i]!=0)
            ret = (ret + count[i]*(count[i]-1)/2) % MOD;
    
    return ret;
}

int main() {
    cin >> n >> k;
    for(int i=1; i<=n; i++) {
        cin >> arr[i];
        psum[i] = (psum[i-1] + arr[i]) % k;
    }
    
    cout << ways();
}
