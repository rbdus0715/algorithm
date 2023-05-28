#include <iostream>
#define MAX 20000
using namespace std;

int N, fence[MAX];
int midHeight;

// i 앞, j 뒤
int solve(int i, int j) {
    if(i==j) return fence[i];
    
    int mid = (i+j)/2;
    
    int result = max(solve(i, mid), solve(mid + 1, j)); 
    int height = min(fence[mid], fence[mid+1]);
    midHeight = height;
    
    result = max(result, 2*height);
    
    int left{mid}, right{mid+1};
    
    for(left; left>=0; left--) {
        height = midHeight;
        height = min(height, fence[left]);
        for(right; right<N; right++) {
            height = min(height, fence[right]);       
            result = max(result, height*(right-left+1));
        }
    }

    return result;
}


int main() {
    cin >> N; for(int i=0; i<N; i++) {
        cin >> fence[i];    
    }
    cout << solve(0, N-1);
}
