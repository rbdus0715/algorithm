#include <iostream>
#include <vector>
using namespace std;

// nCm

// 방법 1 : 무식하게 풀기
void solve_1(int n){
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            for(int k=j+1; k<n; k++){
                for(int l=k+1; l<n; l++){
                    cout << i << j << k << l;
                }
            }
        }
    }
}

// 방법 2 : 재귀함수
void solve_2(int n, vector<int>& picked, int toPick){
    if(toPick==0){
        for(int i:picked) cout << i;
    }
    int smallest = picked.empty() ? 0 : picked.back() + 1;
    for(int next=smallest; next<n; next++){
        picked.push_back(next);
        solve_2(n, picked, toPick-1);
        picked.pop_back();
    }
}

int main(){
    int n; cin >> n;
    solve_1(n);
    cout << '\n';
    vector<int> picked;
    solve_2(n,picked,4);
}
