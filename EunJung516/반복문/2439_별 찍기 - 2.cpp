#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    int n, b;
    string s;
    cin >> n;
    b = n;
    while (n--)
        s += "*", cout << setw(b) << s << '\n';
}