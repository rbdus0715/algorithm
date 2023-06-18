#include <iostream>
using namespace std;

int T, n, w, arr[2][10001], a[10001], b[10001], c[10001];

void d(int start) {
    for(int i=start; i<n; i++) {
        a[i+1] = min(b[i]+1, c[i]+1);
        if(arr[0][i]+arr[1][i]<=w)
            a[i+1] = min(a[i+1], a[i]+1);
        if(i>0 && arr[0][i-1]+arr[0][i]<=w && arr[1][i-1]+arr[1][i]<=w)
            a[i+1] = min(a[i+1], a[i-1]+2);
        if(i<n-1) {
            b[i+1] = a[i+1]+1;
            if(arr[0][i]+arr[0][i+1]<=w)
                b[i+1] = min(b[i+1], c[i]+1);
            c[i+1] = a[i+1]+1;
            if(arr[1][i]+arr[1][i+1]<=w)
                c[i+1] = min(c[i+1], b[i]+1);
        }
    }
}

int main() {
    cin >> T;
    
    while(T--) {
        int ret = 1e9;
        cin >> n >> w;
        for(int i=0; i<n; i++)
            cin >> arr[0][i];
        for(int i=0; i<n; i++)
            cin >> arr[1][i];
        
        // 연결되지 않았을 때
        a[0]=0;
        b[0]=c[0]=1;
        d(0);
        ret = min(ret, a[n]);
    
        // 위에가 연결되어 있을 때
        if(n>1 && arr[0][0]+arr[0][n-1]<=w) {
            a[1] = 1;
            b[1] = 2;
            if(w>=arr[1][0]+arr[1][1]) c[1] = 1;
            else c[1] = 2;
            d(1);
            ret = min(ret, c[n-1]+1);
        }
        
        // 아래가 연결되어 있을 때
        if(n>1 && arr[1][0]+arr[1][n-1]<=w) {
            a[1] = 1;
            c[1] = 2;
            if(w>=arr[0][0]+arr[0][1]) b[1] = 1;
            else b[1] = 2;
            d(1);
            ret = min(ret, b[n-1]+1);
        }
        
        // 위아래 연결되어 있을 때
        if(n>1 && arr[0][0]+arr[0][n-1]<=w && arr[1][0]+arr[1][n-1]<=w) {
            a[1]=0;
            b[1]=c[1]=1;
            d(1);
            ret = min(ret, a[n-1]+2);
        }

        cout << ret << '\n';
    }
}
