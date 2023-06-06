/*
실제 lis 배열 찾기 문제와 마찬가지로 그때 그때의 선택을 알아야한다
lis문제에서는 선택을 배열로 저장해놓았지만
이 문제에서는 더 쉬운 방법을 선택하였다
*/

#include <iostream>
#include <vector>
using namespace std;

int N, K, W[101], V[1001], dp[101][1001];
string thing[101];
vector<int> result;

int d(int item, int cap) {
    if(item==N) return 0;
    
    int& ret = dp[item][cap];
    if(ret!=-1) return ret;
    
    ret = d(item+1, cap);
    if(W[item]<=cap) ret = max(ret, d(item+1, cap-W[item])+V[item]);
    
    return ret;
}

void tracking(int item, int cap) {
    if(item==N) return;
    
    // 선택하지 않은 경우
    if(d(item, cap)==d(item+1, cap)) tracking(item+1, cap);
    
    // 선택한 경우
    else {
        result.push_back(item);
        tracking(item+1, cap-W[item]);
    }
}

int main() {
    cin >> N >> K; 
    for(int i=0; i<N; i++) {
        cin >> thing[i] >> W[i] >> V[i]; 
    }
    for(int i=0; i<N; i++) {
        for(int j=0; j<=K; j++) dp[i][j] = -1;
    }
    
    // 배낭 문제 결과 출력
    cout << d(0, K) << " ";
    
    // 역추적을 통해서 실제 답 구하기
    tracking(0, K);
    
    // 물건 개수
    cout << result.size() << "\n";
    // 물건 출력
    for(int i:result) cout << thing[i] << "\n";
}

/*
input:
6 10
laptop 4 7
camera 2 10
xbox 6 6
grinder 4 7
dumbell 2 5
encyclopedia 10 4

output:
24 3
laptop
camera
grinder
*/
