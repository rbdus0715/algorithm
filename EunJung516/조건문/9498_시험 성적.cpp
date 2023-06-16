#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int a;
    cin >> a;
    cout << (a > 89 ? 'A' : (a > 79 ? 'B' : (a > 69 ? 'C' : (a > 59 ? 'D' : 'F'))));
}