#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b;
    cin >> a >> b;
    b -= 45;
    if (b < 0)
        --a, b += 60;
    cout << a + (a < 0 ? 24 : 0) << ' ' << b;
}