#include <iostream>
using namespace std;

int n, m, a, b, c, u[105];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> m;
    while (m--)
    {
        cin >> a >> b >> c;
        while (a <= b)
            u[a++] = c;
    }
    for (int i = 1; i <= n; ++i)
        cout << u[i] << ' ';
}