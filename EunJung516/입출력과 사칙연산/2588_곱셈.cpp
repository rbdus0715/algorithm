#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << a * (b % 10) << '\n'
         << a * ((b % 100) / 10) << '\n'
         << a * (b / 100) << '\n'
         << a * b;
}