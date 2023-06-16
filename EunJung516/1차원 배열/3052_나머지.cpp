#include <iostream>
using namespace std;

int n = 10, u, v, a[42];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (n--)
    {
        cin >> u;
        u %= 42;
        if (!a[u])
            ++v, a[u] = 1;
    }
    cout << v;
}