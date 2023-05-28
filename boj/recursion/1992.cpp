#include <iostream>
using namespace std;

/*
별것도 아닌 것 때문에 해맨 문제. 결국 중요한 것을 깨달았다.
string을 입력 받을 때 '\0'까지 입력받는 다는 것을 간과하고 있어서
배열을 최대 입력인 64에 맞춰 arr[64][64] 크기로 설정해놨다.
그런데 실제로 64크기 string을 입력 받을 때 '\0'까지 입력받아버려서
길이에 차이가 생겨 어떤 문제가 생긴 듯 하다.
이거 알려준 은정이 고마워..
*/

int N;
char arr[64][64];
 
void solve(int y, int x, int size) {
    if(size==1){
        cout << arr[y][x]-'0'; 
        return;
    }
    
    bool all_0{true}, all_1{true};
    for(int i=y; i<y+size; i++) {
        for(int j=x; j<x+size; j++) {
            if(arr[i][j]=='0') all_1 = false;
            if(arr[i][j]=='1') all_0 = false;
        }
    }

    if(all_0) {
        cout << 0;
        return;
    } 
    
    if(all_1) {
        cout << 1;
        return;
    }
    
    cout << "(";
    solve(y, x, size/2);
    solve(y, x+size/2, size/2);
    solve(y+size/2, x, size/2);
    solve(y+size/2, x+size/2, size/2);
    cout << ")";
} 

int main() {
    cin >> N;
    for(int i=0; i<N; i++) {
        string s; cin >> s;
        for(int j=0; j<N; j++) {
            arr[i][j] = s[j];
        }
    }
    solve(0, 0, N);
    cout << endl;
}
