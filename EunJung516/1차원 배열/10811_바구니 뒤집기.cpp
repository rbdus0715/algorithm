#include <iostream>
using namespace std;

int n, m, u, v, a[101];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        a[i] = i;
    while (m--)
    {
        cin >> u >> v;
        for (int i = 0; i < (v - u + 1) / 2; ++i)
            a[u + i] ^= a[v - i] ^= a[u + i] ^= a[v - i];
    }
    for (int i = 1; i <= n; ++i)
        cout << a[i] << ' ';
}