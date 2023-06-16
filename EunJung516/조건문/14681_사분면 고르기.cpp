#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << (a > 0 ? (b > 0 ? 1 : 4) : (b > 0 ? 2 : 3));
}