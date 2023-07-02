#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/*
전위순회, 중위순회가 주어졌을 때 후위순회를 구하기
7
27 16 9 12 54 36 72
9 12 16 27 36 54 72

12 9 16 36 72 54 27 
*/

int n;

vector<int> slice(vector<int> v, int a, int b) {
    return vector<int>(v.begin() + a, v.begin() + b);
}

void solve(vector<int> preorder, vector<int> inorder) {
    int N = preorder.size();
    
    if(N == 0) return;

    int root = preorder[0];
    
    int leftSize = find(inorder.begin(), inorder.end(), root) - inorder.begin();
    int rightSize = N - leftSize - 1;
    
    solve(slice(preorder, 1, leftSize+1), slice(inorder, 0, leftSize));
    solve(slice(preorder, leftSize+1, N), slice(inorder, leftSize+1, N));
    
    cout << root << " ";
}

int main() {
    cin >> n;
    vector<int> preorder;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        preorder.push_back(x);
    }
    vector<int> inorder;
    for(int i=0; i<n; i++) {
        int x; cin >> x;
        inorder.push_back(x);
    }
    
    solve(preorder, inorder);
}
