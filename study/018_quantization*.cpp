#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int N, P, partSum[101], partSqSum[101], dp[101][11];
vector<int> arr;

void preprocess() {
    sort(arr.begin(), arr.end());
    partSum[0] = A[0];
    partSqSum[0] = A[0]*A[0];
    for(int i=1; i<N; i++) {
        partSum[i] = partSum[i-1] + A[i];
        partSqSum[i] = partSqSum[i-1] + A[i]*A[i];
    }
}

int d(int i, int part) {
    if(i==1) return 0;
    int& ret = dp[i][part];
    if(ret != -1) return ret;
    
    for(int partSize=1; i-1+PartSize<N; i++) {
        ret = min(ret, )
    }
    
    return ret;
}

int main() {
    cin >> N >> P;
    for(int i=0; i<N; i++) {
        int x; cin >> x; arr.push_back(x);
        for(int j=0; j<P; j++) dp[i][j] = -1;
    }
    preprocess();
    cout << d(0, P);
}
