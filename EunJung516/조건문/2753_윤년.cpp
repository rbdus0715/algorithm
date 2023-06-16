#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int a;
    cin >> a;
    cout << (!(a % 400) || !(a % 4) && (a % 100) ? 1 : 0);
}