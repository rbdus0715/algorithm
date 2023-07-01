# 비트마스크 (7/1)
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
# 부분 합 (7/1)
- 구간 합을 빠르게 계산하기 위해 부분 합을 미리 계산해놓기
- 다차원으로도 확장 가능
# 선형 자료 구조 (7/1)
- 동적 배열
  - skip
- 연결 리스트
# 큐와 스택, 덱

# 문자열

# 트리

# 그래프

