#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b, c;
    cin >> a >> b >> c;
    b += c;
    if (b > 59)
        c = b / 60, a += c, b -= c * 60;
    cout << a - (a > 23 ? 24 : 0) << ' ' << b;
}