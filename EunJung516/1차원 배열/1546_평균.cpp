#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    double n, mx = 0, s = 0, a[1000];
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i], mx = max(mx, a[i]), s += a[i];
    cout << s / mx * 100 / n;
}