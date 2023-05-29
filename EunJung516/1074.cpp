#include <iostream>
using namespace std;

int n, r, c, sz = 1, an;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0);
    cin >> n >> r >> c;
    while (--n)
        sz *= 2;
    while (sz)
    {
        if (r < sz && c < sz)
            ;
        else if (r < sz)
            an += sz * sz, c -= sz;
        else if (c < sz)
            an += sz * sz * 2, r -= sz;
        else
            an += sz * sz * 3, r -= sz, c -= sz;
        sz /= 2;
    }
    cout << an;
}