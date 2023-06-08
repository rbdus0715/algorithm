#include <iostream>
using namespace std;
// 모스부호 k번째 계산하기



// 재귀를 이용한 완전탐색으로 모든 모스부호를 구할 수 있다
void generate(int n, int m, string s) {
    if(m==0&&n==0) {
        cout << s << '\n';
        return;
    }
    if(n>0) generate(n-1, m, s+'-');
    if(m>0) generate(n, m-1, s+'o');
}


// 위의 코드에서 k-1번째까지를 스킵하고 k번째만 출력하는 방법으로 변형하여 사용할 수 있다
// 하지만 그렇게 되면 k가 엄청나게 커진다면 수행시간이 너무 커질 것이다
int skip;

void generate2(int n, int m, string s) {
    if(skip<0) return;
    if(m==0&&n==0) {
        if(skip==0) cout << s << '\n';
        skip--;
        return;
    }
    if(n>0) generate2(n-1, m, s+'-');
    if(m>0) generate2(n, m-1, s+'o');
}

/*
int main() {
    cin >> skip;
    skip--;
    string a = "";
    generate2(2, 2, a);
}
*/



// 위의 코드에서 조금만 개선을 해보자
// skip의 수가 남은 m,n개의 점로 만들어질 수 있는 부호 조합이 같거나 크다면 그걸 굳이 세야할까?
// m+nCm 만큼을 건너뛸 수 있는 것이다

#include <iostream>
using namespace std;

int skip;
// k의 최대값 + 100을 상한선으로 잡아 오버플로우가 일어나지 않도록 한다. >> 나중에 이용할 때도 주의할점
const int M = 1000000000+100;
int bino[201][201];

void cal_bino() {
    for(int i=0; i<=200; i++) {
        bino[i][0] = bino[i][i] = 1;
        for(int j=0; j<=200; j++) {
            bino[i][j] = min(M, bino[i-1][j-1] + bino[i-1][j]);
        }
    }    
}


void generate2(int n, int m, string s) {
    if(skip<0) return;
    if(m==0&&n==0) {
        if(skip==0) cout << s << '\n';
        skip--;
        return;
    }
    if(bino[n][m]<=skip) {
        skip -= bino[n][m];
        return;
    }
    
    if(n>0) generate2(n-1, m, s+'-');
    if(m>0) generate2(n, m-1, s+'o');
}

int main() {
    cin >> skip;
    skip--;
    string a = "";
    cal_bino();
    generate2(2, 2, a);
}










































