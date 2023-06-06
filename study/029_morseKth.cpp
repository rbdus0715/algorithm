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

int main() {
    cin >> skip;
    skip--;
    string a = "";
    generate2(2, 2, a);
}



//
