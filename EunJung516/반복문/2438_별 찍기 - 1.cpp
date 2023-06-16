#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n;
    string s;
    cin >> n;
    while (n--)
        s += "*", cout << s << '\n';
}