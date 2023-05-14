#include <iostream>
#include <vector>
using namespace std;

const int MIN = -2e9;

// 방법 1 : 다 확인
int solve_1(const vector<int>& A){
    int N = A.size(), ret = MIN;
    for(int i=0; i<N; i++){
        for(int j=i; j<N; j++){
            int sum = 0;
            for(int k=i; k<j; k++){
                sum += A[k];
            }
            ret = max(ret, sum);
        }
    }
    return ret;
}

// 방법 2 : 중복 계산 없애기
int solve_2(const vector<int>& A){
    int N = A.size(), ret = MIN;
    for(int i=0; i<N; i++){
        int sum = 0;
        for(int j=i; j<N; j++){
            sum += A[j];
            ret = max(ret, sum);
        }
    }
    return ret;
}

// 방법 3 : 분할 정복 -> 배열을 반으로 나눌 때 최대합부분수열의 위치는 다음 두가지 케이스이다.
// 1) 두 조각 모두에 걸쳐있다.
// 2) 두 조각 중 하나에만 속해있다.
int solve_3(const vector<int>& A, int lo, int hi){
    // 기저 케이스
    if(lo==hi) return A[lo];
    
    // 1번 케이스
    int mid = (lo+hi)/2;
    int left = MIN, right = MIN, sum = 0;
    
    for(int i=mid; i>=lo; i--){
        sum += A[i];
        left = max(left, sum);
    }
    
    sum = 0;
    
    for(int j=mid+1; j<=hi; j++){
        sum += A[j];
        right = max(right, sum);
    }
    
    // 2번 케이스
    int single = max(solve_3(A, lo, mid), solve_3(A, mid+1, hi));
    
    return max(left+right, single);
}

// 방법 4 : 다이나믹 프로그래밍
int solve_4(const vector<int>& A){
    int N = A.size(), ret = MIN, psum = 0;
    for(int i=0; i<N; i++){
        psum = max(0, psum) + A[i];
        ret = max(ret, psum);
    }
}

int main(){
    vector<int> arr;
    int N; cin >> N;
    for(int i=0; i<N; i++){
        int x; cin >> x; arr.push_back(x);
    }
    // cout << solve_3(arr, 0, N-1);
}

