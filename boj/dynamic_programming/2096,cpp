#include <iostream>
#include <cstring>
#define MAX 100001
using namespace std;

int N, x, y, z, k, max_[2][3], min_[2][3], maxAns, minAns;

int main() {
    cin >> N;
    
    for(int i=0; i<N; i++) {
        cin >> x >> y >> z;
        
        max_[k][0] = max(max_[1-k][0], max_[1-k][1]) + x;
        max_[k][1] = max(max(max_[1-k][0], max_[1-k][1]), max_[1-k][2]) + y;
        max_[k][2] = max(max_[1-k][1], max_[1-k][2]) + z;
        
        min_[k][0] = min(min_[1-k][0], min_[1-k][1]) + x;
        min_[k][1] = min(min(min_[1-k][0], min_[1-k][1]), min_[1-k][2]) + y;
        min_[k][2] = min(min_[1-k][1], min_[1-k][2]) + z;
        
        k = 1 - k;
    }
    
    maxAns = max(max(max_[1-k][0],max_[1-k][1]),max_[1-k][2]);
    minAns = min(min(min_[1-k][0],min_[1-k][1]),min_[1-k][2]);
    
    cout << maxAns << " " << minAns;
}
