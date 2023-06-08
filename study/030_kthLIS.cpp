#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// k는 10^9 이하, 모든 s[i]는 자연수
int N, K, S[501], dp[501], cntdp[501];
vector<int> lis;

int d(int i) {
    int& ret = dp[i];
    if(ret) return ret;
    
    ret = 1;
    for(int next=i+1; next<=N; next++) {
        if(S[i]<S[next]) ret = max(ret, d(next) + 1);
    }
    return ret;
}

int count(int i) {
    if(d(i)==1) return 1;
    
    int& ret = cntdp[i];
    if(ret) return ret;
    
    ret = 0;
    for(int next=i+1; next<=N; next++) {
        if(S[i]<S[next] && d(i)==d(next)+1) ret += count(next);
    }
    return ret;
}

void calLIS(int i, int skip) {
    if(i) lis.push_back(S[i]);
    
    vector<pair<int, int> > nextList;
    for(int next=i+1; next<=N; next++) {
        if(S[i]<S[next] && d(i)==d(next)+1) 
            nextList.push_back(make_pair(S[next], next));
    }
    sort(nextList.begin(), nextList.end());
    
    for(int i=0; i<nextList.size(); i++) {
        int nextIndex = nextList[i].second;
        int nextValue = nextList[i].first;
        if(skip>=count(nextIndex)) skip -= count(nextIndex);
        else {
            calLIS(nextIndex, skip);
            break;
        }
    }
}

int main() {
    cin >> N >> K;
    for(int i=1; i<=N; i++) cin >> S[i];
    cout << d(0) - 1 << "\n" << count(0) << "\n";
    calLIS(0, K);
    for(int i:lis) cout << i << " ";
}
