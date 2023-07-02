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
- 이진 검색 트리
  - 이진 트리란 : 각 노드가 최대 두 개의 자식 노드만을 가질 수 있는 트리
  - 이진 검색 트리 구성 : 왼쪽 서브 트리에는 해당 노드보다 작은 노드들이, 오른쪽에는 큰 노드들이 담겨있음
    - 성질 : 중위 순회를 하면 크기 순서대로 정렬된 원소의 목록을 얻음 >> 그 말은 곧 최대 최소 원소를 빠르게 구할 수 있다는 것
  - *장점 : 집합에 원소를 추가하거나 삭제하는 조작 연산이 쉬움*
  - x보다 작은 원소의 수 찾기 / k번째 원소 찾기 쉽게 구현 가능
  - 시간 복잡도 : 최대 재귀 호출의 횟수는 O(h) 트리의 높이 >> 높이가 낮아야 좋음 >> 균형잡힌 트리
- 균형 잡힌 이진트리 (트리의 높이가 항상 O(logN)을 유지, 대표적으로 레드-블랙 트리, 표준 라이브러리의 이진 검색 트리 구현도 레드-블랙 트리로 만들어짐)

# 그래프

# 문자열
