#include <iostream>
using namespace std;

int n, m, a, b, u[105];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        u[i] = i;
    while (m--)
    {
        cin >> a >> b;
        if (a != b)
            u[a] ^= u[b] ^= u[a] ^= u[b];
    }
    for (int i = 1; i <= n; ++i)
        cout << u[i] << ' ';
}