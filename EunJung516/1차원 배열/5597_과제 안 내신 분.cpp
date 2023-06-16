#include <iostream>
using namespace std;

int n = 28, u, a[31];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    while (n--)
        cin >> u, a[u] = 1;
    for (int i = 1; i < 31; ++i)
        if (!a[i])
            cout << i << '\n';
}