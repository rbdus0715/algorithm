# 비트마스크
[공부 링크](http://graphics.stanford.edu/~seander/bithacks.html)
### 장점 : 더 빠르고 간결, 작은 용량
*주의할 점 : 비트연산자의 우선순위는 비교 연산자보다 낮아 무조건 ()로 묶는다*
- [집합 구현](https://github.com/rbdus0715/algorithm/blob/main/study2/001_bitmaskBasic.cpp)
- 15퍼즐 상태 표현하기
  ```
  typedef unsigned long long uint64;
  // mask의 index 위치에 쓰인 값을 반환한다.
  int get(uint64 mask, int index) { return (mask >> (index << 2)) & 15; }
  ```
- 언제 비트마스킹을 떠올리나?
  - 집합을 사용해야할 때
  - 만들어야하는 배열 용량이 너무 클 때
# 부분 합
- 구간 합을 빠르게 계산하기 위해 부분 합을 미리 계산해놓기
- 다차원으로도 확장 가능
# 선형 자료 구조
- 동적 배열
  - skip
- 연결 리스트
# 큐와 스택, 덱
- 사용 예시
  - 큐 : 조세푸스 문제를 원형 큐로 돌려 쉽게 풀 수 있다.
  - 스택 : 울타리 자르기 문제에서 o(n) 시간만에 스위핑과 스택을 통해 쉽게 가능함 > i번째 울타리를 스위핑 하면서 아직 오른쪽 끝이 나지 않은 막대들을 모두 스택에 넣어두고 한번에 처리할 
# 트리
- 기본 원리
```
struct TreeNode {
    int x;
    TreeNode* parent;
    vector<TreeNode*> children;
}

void print(TreeNode* root) {
    cout << root->x << endl;
    for(int i=0; i<root->children.size(); i++)
        print(root->children[i]);
}

int height(TreeNode* root) {
    int h = 0;
    for(int i=0; i<root->children.size(); i++)
        h = max(h, 1 + height(root->children[i]));
    
    return h;
}
```
- [트리의 순회]()
  - 전위순회 : 맨 처음에 루트를 방문, 왼쪽과 오른쪽 서브트리를 순서대로 방문
  - 중위순회 : 왼쪽과 오른쪽 서브트리 사이에 트리의 루트를 방문
  - 후위순회 : 왼쪽과 오른쪽 서브트리를 모두 방문한 후 루트를 방문
# 그래프

# 문자열
