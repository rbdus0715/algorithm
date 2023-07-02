#include <iostream>
#include <cmath>
using namespace std;

int main() {
    int t;
    cin >> t;
    while(t--) {
        int x, y, dist, d;
        cin >> x >> y;
        dist = y - x;
        d = sqrt(dist);
        
        int ans;
        if(pow(d,2)==dist) ans = 2*d-1;
        else ans = 2*d;
        
        if(dist>d*(d+1)) ans += 1;
        
        cout << ans << endl;
    }
} 
