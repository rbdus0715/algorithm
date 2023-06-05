/*
dp를 역추적하여 실제 최적해를 구하는 방법
*/

#include<iostream>
using namespace std;

int N, arr[501], dp[501], nextIndex[501], result, maxIndex;

int d(int i) {
    int& ret = dp[i];
    if(ret) return ret;
    
    ret = 1;
    
    for(int j=i+1; j<N; j++) {
        if(arr[i]<arr[j] && ret<d(j)+1) {
            ret = d(j)+1;
            nextIndex[i] = j;
        }
    }
    
    return ret;
}

void realLis(int i, int length) {
    cout << arr[i] << " ";
    if(length==result) return;
    realLis(nextIndex[i], length+1);
}

int main() {
    cin >> N;
    for(int i=0; i<N; i++) cin >> arr[i];
    
    for(int i=0; i<N; i++) {
        if(result<d(i)) {
            result = d(i);
            maxIndex = i;
        }
    }

    realLis(maxIndex, 1);
}







