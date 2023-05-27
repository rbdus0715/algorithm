#include <iostream>
using namespace std;

int N, a[49];

// 내 풀이
void solve(int cur, int n, int result[6]) {
    if(n==0) {
        result[5] = a[cur];
        for(int i=0; i<6; i++) cout << result[i] << " ";
        cout << "\n";
    }
    
    else {
        result[5-n] = a[cur];
        for(int i=cur+1; i<=N-n; i++) {
            solve(i, n-1, result);
        }
    }
}

// 다른 풀이 (1)
/*
나랑 다른점:
(1) dfs로 풀음
(2) 함수에 인자로 배열을 쓰지 않음
모든 케이스를 전부 살핀다.
첫 시작이 입력받은 배열의 맨 마지막 원소부터 시작할 수도 있는데 그 케이스도 처리하긴 하지만
결국에는 종료조건이나 재귀조건 둘다 만족시키지 못하므로 그 케이스는 실현되지 않음
*/
void dfs(int start, int depth) {
	
	//종료조건
	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << ans[i] << " ";
		}
		cout << endl;
		return;
	}

	//재귀: 재귀가 return 되면 다시 다음문자에 대해 dfs
	for (int i = start; i < num; i++) {
		ans[depth] = lotto[i];
		dfs(i + 1, depth+1);
	}

}

int main() {
    cin >> N; while(N!=0) {
        
        for(int i=0; i<N; i++) cin >> a[i];
        int result[6] = {};
        
        for(int i=0; i<N-5; i++){
            solve(i, 5, result);
        }
        
        cout << "\n";
        cin >> N;
    }
}
