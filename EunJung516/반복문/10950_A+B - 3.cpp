#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b, t;
    cin >> t;
    while (t--)
        cin >> a >> b, cout << a + b << '\n';
}