#include <iostream>
using namespace std;

// 최장 증가 부분 수열 (LIS)

int N, arr[1001], dp[1001];

int d(int i) {
    int& ret = dp[i];
    if(ret) return ret;
    ret = 1;
    for(int next=i+1; next<N; next++) {
        if(arr[i]<arr[next]) ret = max(ret, d(next)+1);
    }
    return ret;
}

int main() {
    cin >> N; for(int i=0; i<N; i++) cin >> arr[i];
    int ans = 0;
    for(int i=0; i<N; i++) ans = max(ans, d(i));
    cout << ans;
}
