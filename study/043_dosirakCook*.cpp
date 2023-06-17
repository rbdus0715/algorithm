#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n, x, y;
vector<pair<int, int> > dosirak;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        cin >> x >> y;
        dosirak.push_back(make_pair(y, x));
    }
    sort(dosirak.begin(), dosirak.end());
    
    int ret=0, beginEat=0;
    for(int i=n-1; i>=0; i--) {
        beginEat += dosirak[i].second;
        ret = max(ret, beginEat + dosirak[i].first);
    }
    cout << ret;
}
