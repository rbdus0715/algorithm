#include <iostream>
using namespace std;

int n, b, a[205];

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n;
    while (n--)
        cin >> b, ++a[b + 100];
    cin >> b;
    cout << a[b + 100];
}