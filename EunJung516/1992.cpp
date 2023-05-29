#include <iostream>
using namespace std;

int n;
char c[65][65];

void sol(int u, int v, int w)
{
    if (w == 1)
    {
        cout << c[u][v];
        return;
    }

    int n, f0 = 1, f1 = 1;
    for (int i = u; i < u + w; ++i)
        for (int j = v; j < v + w; ++j)
            c[i][j] == '1' ? f0 = 0 : f1 = 0;

    if (f0)
        cout << 0;
    else if (f1)
        cout << 1;
    else
        cout << '(', n = w / 2, sol(u, v, n), sol(u, v + n, n), sol(u + n, v, n), sol(u + n, v + n, n), cout << ')';
}

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> c[i];
    sol(0, 0, n);
}