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

/*
새로 배운 내용
main함수에서 최종적으로 for문을 통해서 d(i)를 다 계산했다. 이유는 위에서도 말했듯이 계산되지 않는 d(i)가 생기기 때문이다.
이것을 해결하는 방법으로는 dp[]열에 arr[0]에 -2e9를 해 놓고, d(0)로부터 시작하면 모든 배열의 원소보다 arr[0]이 작으므로
(arr[i]<arr[next] 조건) 모든 dp(i)가 실행될 것이다.
이후 결과는 d(0)-1을 해야한다. 이유는 d(0)는 원래 배열에서 생각하지 않았던 0번째 배열까지 길이를 계산한 것이기 때문에
1을 빼줘야한다.
*/

int main() {
    cin >> N; for(int i=0; i<N; i++) cin >> arr[i];
    int ans = 0;
    for(int i=0; i<N; i++) ans = max(ans, d(i));
    cout << ans;
}
