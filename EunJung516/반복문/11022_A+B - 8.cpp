#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b, t;
    cin >> t;
    for (int i = 1; i <= t; ++i)
        cin >> a >> b, cout << "Case #" << i << ": " << a << " + " << b << " = " << a + b << '\n';
}