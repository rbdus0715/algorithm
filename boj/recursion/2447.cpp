#include <iostream>
using namespace std;

void solve(int i, int j, int N) {
    // i/N이 우선 0이 아니어야 하므로 i>N
    // 그 결과가 기본 모양 (3*3)의 가운데여야 하므로 %3==1
    // 중요한 성질
    // 나머지 (%) : 나누는 수에서 몇 번째에 해당하는지 => mod=1인것과 mod=2인것들의 성질이 같은 것처럼 그룹이 형성됨
    // 정수 나누기 (/) : 범위를 작게 만들어줌
    if( ((i/N)%3==1) && ((j/N)%3==1) ) {
        cout << " ";
    }
    else {
        // N/3==0이 되려면 N이 0이어야함
        if(N/3==0) {
            cout << "*";
        }
        else solve(i, j, N/3);  
    }
}

int main(){
    int N;
    cin >> N;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            solve(i,j,N);
        }
        cout << "\n";
    }
}
