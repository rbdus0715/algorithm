#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n = 9, mx = 0, idx, a;
    while (n--)
    {
        cin >> a;
        if (mx < a)
            mx = a, idx = 9 - n;
    }
    cout << mx << '\n'
         << idx;
}