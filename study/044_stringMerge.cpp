//11066 파일 합치기 문제

#include <iostream>
#include <queue>
using namespace std;

// 최소 큐
priority_queue<int, vector<int>, greater<int> > pq;
int n, ret;

int main() {
    cin >> n;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        pq.push(x);
    }
    
    while(pq.size()>1) {
        int min1 = pq.top(); pq.pop();
        int min2 = pq.top(); pq.pop();
        pq.push(min1+min2);
        ret+= min1+min2;
    }
    cout << ret;
}
