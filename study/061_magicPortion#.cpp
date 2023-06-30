#include <iostream>
#include <vector>
using namespace std;

int gcd(int n, int m) {
    if(m==0) return n;
    else return gcd(m, n%m);
}

int n, recipe[201], cur[201];

vector<int> solve() {
    int m = recipe[0];
    for(int i=1; i<n; i++)
        m = gcd(m, recipe[i]);
    
    
}

int main() {
    cin >> n;
    for(int i=0; i<n; i++)
        cin >> recipe[i];
    for(int i=0; i<n; i++)
        cin >> cur[i];
    
    vector<int> ret = solve();
    for(int i:ret)
        cout << i << " ";
}
