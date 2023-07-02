#include <iostream>
#include <random>
using namespace std;

// x보다 작은 원소 계산 or k번재 원소 찾는 연산을 지원하지 않기 때문에 직접 구현
// 구현이 간단한 '트립'을 이용함

type int KeyType;
struct Node {
    // value
    KeyType key;
    // 이 노드의 우선순위와 이 노드를 루트로 하는 서브트리의 크기
    int priority, size;
    // 두 자식 포인터
    Node *left, *right;
    // 생성자에서 난수 우선순위 생성하고, size와 left/right 초기화
    Node(const KeyType& _key) 
    : key(_key), priority(rand()), size(1), left(NULL), right(NULL) {}
    
    void setLeft(Node* newLeft) {left = newLeft; calcSize();}
    void setLeft(Node* newRight) {right = newRight; calcSize();}
    
    // size 멤버 갱신
    void calcSize() {
        size = 1;
        if(left) size += left->size;
        if(right) size += right->size;
    }
};
