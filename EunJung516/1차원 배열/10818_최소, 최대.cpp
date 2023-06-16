#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, a, mn = 1e7, mx = -1e7;
    cin >> n;
    while (n--)
        cin >> a, mn = min(mn, a), mx = max(mx, a);
    cout << mn << ' ' << mx;
}