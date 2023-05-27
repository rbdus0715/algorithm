#include <iostream>
using namespace std;

int N, a[49];

void solve(int cur, int n, int result[6]) {
    if(n==0) {
        result[5] = a[cur];
        for(int i=0; i<6; i++) cout << result[i] << " ";
        cout << "\n";
    }
    
    else {
        result[5-n] = a[cur];
        for(int i=cur+1; i<=N-n; i++) {
            solve(i, n-1, result);
        }
    }
}

int main() {
    cin >> N; while(N!=0) {
        
        for(int i=0; i<N; i++) cin >> a[i];
        int result[6] = {};
        
        for(int i=0; i<N-5; i++){
            solve(i, 5, result);
        }
        
        cout << "\n";
        cin >> N;
    }
}
