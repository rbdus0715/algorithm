#include <iostream>
#include <string>
using namespace std;

int N;
const int dx[8]={0,1,1,1,0,-1,-1,-1};
const int dy[8]={-1,-1,0,1,1,1,0,-1};
char a[5][5];

bool search(int y, int x, string s){
    
    if(x<0||x>4||y<0||y>5) return false;
    if(s[0]!=a[y][x]) return false;
    if(s.size()==1) return true; //#1

    for(int i=0; i<8; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(search(ny, nx, s.substr(1))) return true; //#2
    }
    
    return false; //#3
}

/* 헷갈렸던 곳 표시 -> //#
#1: 재귀함수의 종료 조건을 잘 생각하지 못했다.
기저 사례는 무엇일까? 다음 두가지이다.
위치에 있는 글자가 원하는 단어의 첫 글자가 아닌 경우
위의 경우가 아니면서 단어가 1글자인 경우
#2: 처음 코딩할 때 return true를 적지 않았다.
처음에는 그냥 for문 안에 search 함수가 그냥 있었다. 하지만 이렇게 될 경우 함수가 true/false를 반환하여 전체 함수가 종료되어 버린다.
그렇기 때문에 if를 통해 search의 여부를 확인하고 맞을 때만 return true하여야 한다.
#3: true가 될 조건을 모두 지나쳐버렸으므로 마지막은 false를 반환해야한다.

// 다음에 풀 때 기저 사례와 종료 조건을 잘 파악해야겠다.
*/
/*
urlpm
xpret
giaet
xtnzy
xoqrs

pretty
girl
repeat
*/
int main(){
    for(int i=0; i<5; i++) cin >> a[i];
    cin >> N; while(N--){
        bool stop{false}; string s; cin >> s;
        for(int i=0; i<5; i++){
            for(int j=0; j<5; j++){
                if(search(i,j,s)){
                    cout << "True\n";
                    stop=true;
                    break;
                }
            }
            if(stop) break;
        }
        if(!stop) cout << "False\n";
    }
}
