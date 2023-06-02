#include <iostream>
#include <cmath>
using namespace std;

int N;

void solve(int size) {
    
    // 기저 사례
    if(size==1) cout << "-";
    else {
        int nextSize = size/3;
        
        // 앞
        solve(nextSize);
        
        // 가운데
        for(int i=0; i<nextSize; i++) cout << " ";
        
        // 뒤
        solve(nextSize);
    }
}

int main() {
    while(cin>>N){
        int size = pow(3, N);
        solve(size);
        cout << "\n";
    }
}

/*
---------------------------
---------         ---------
---   ---         ---   ---
- -   - -         - -   - -
*/
