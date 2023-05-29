/*
전에 백준에서 풀었을 때는 재귀로 안 풀었는데 뭔가 재귀로 내가 원리를 상상하면서 푸니깐
확실히 재귀가 이해는 쉬운 것 같다.

마지막 코드 부분에서 실수했었는데
    d(0);
    for(int i=0; i<N; i++) ans = max(ans, d(i));
이렇게 d(0)를 하면 재귀적으로 모든 dp[i]가 완성될 줄 알았는데 생각해보니깐 arr[i]<arr[next] 조건이 부합할 때만
방문하므로 방문하지 않는 곳이 생길 수 있겠다는 생각을 했다.
실제 그 반례가 무엇인지는 모른다.
그래서 for문으로 d(i)함수를 다 돌려서 모든 dp[i]값들을 구했다.
*/

#include <iostream>
using namespace std;

int N, arr[1001], dp[1001];

int d(int i) {
    int& ret = dp[i];
    if(ret) return ret;
    ret = 1;
    for(int next=i+1; next<N; next++) {
        if(arr[i]<arr[next]) ret = max(ret, d(next)+1);
    }
    return ret;
}

int main() {
    cin >> N; for(int i=0; i<N; i++) cin >> arr[i];
    int ans = 0;
    for(int i=0; i<N; i++) ans = max(ans, d(i));
    cout << ans;
}
