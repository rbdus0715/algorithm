#include <iostream>
using namespace std;

int bitSize(int x) {
    if(x == 0) return 0;
    return x % 2 + bitSize(x / 2);
}

int main() {
    
    // n가지 선택 가능
    int n;
    cin >> n;
    
    // 공집합, 꽉 찬 집합
    int emptySet = 0;
    int fullSet = (1 << n) - 1;
    
    // 원소 추가 : or 연산자
    int p = 2;
    emptySet |= (1 << p);
    
    // 원소 포함 여부 확인
    bool have = emptySet & (1 << p);
    
    // 원소의 삭제
    // 1 : 이미 있는 경우
    emptySet -= (1 << p); 
    // 2 : 없는 경우도 포함
    // ~(1 << p)는 해당 비트만 꺼지고 나머지는 모두 켜져있는 상태
    emptySet &= ~(1 << p);    
    
    // 원소의 토글 (반대로)
    emptySet ^= (1 << p);
    
    
    // 두 집합에 대한 연산
    int a = 4 // 100
    int b = 3 // 011
    // 1. 합집합
    int added = (a | b);
    int intersection = (a & b);
    int removed = (a & ~b) // a-b
    int toggled = (a ^ b); // a와 b중 하나에만 포함된 원소들의 집합
    
    
    // 집합의 크기 구하기 (원소의 수)
    int size = bitSize(a);
    /*
    gcc/g++ : __builtin_popcount(a);
    visual c++ : __popcnt(a);
    */
    
    
    // 최소 원소 찾기
    /*
    gcc/g++ : __builtin_ctz(a);
    visual c++ : _BitScanForward(&index, a);
    */
}










