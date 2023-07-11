#include <iostream>
#include <vector>
#include <limits>
using namespace std;

struct RMQ {
    // 배열 길이
    int n;
    // 각 구간의 최소치
    vector<int> rangeMin;
    
    RMQ(const vector<int>& array) {
        n = array.size();
        rangeMin.resize(n*4);
        init(array, 0, n-1, 1);
    }
    
    int init(const vector<int>& array, int left, int right, int node) {
        if(left == right)
            return rangeMin[node] = array[left];
        int mid = (left + right) / 2;
        int leftMin = init(array, left, mid, node*2);
        int rightMin = init(array, mid+1, right, node*2+1);
        return rangeMin[node] = min(leftMin, rightMin);
    }

    // 임의의 구간의 최소치를 구하는 쿼리
    const int INT_MAX = numeric_limits<int>::max();
    int query(int left, int right, int node, int nodeLeft, int nodeRight) {
        if(right < nodeLeft || left > nodeRight)
            return INT_MAX;
        if(left <= nodeLeft && nodeRight <= right)
            return rangeMin[node];
        
        int mid = (nodeLeft + nodeRight) / 2;
        return min(query(left, right, node*2, nodeLeft, mid), query(left, right, node*2+1, mid+1, nodeRight));
    }
    
    int query(int left, int right) {
        return query(left, right, 1, 0, n-1);
    }
};

int main() {
    int n, temp;
    cin >> n;
    vector<int> a;
    for(int i=0; i<n; i++) {
        cin >> temp;
        a.push_back(temp);
    }
    RMQ segTree = RMQ(a);
    
    int l, r; 
    cin >> l >> r;
    cout << segTree.query(l, r);
}
