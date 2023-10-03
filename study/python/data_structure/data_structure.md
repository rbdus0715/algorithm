## 스택 구현
```python
# 초기화
stack = []

# push
stack.append(n)

# pop
top = stack.pop()

# top
top = stack[-1]
```

## 큐, 덱
```python
from collections import deque

# 생성
# 괄호 안에는 리스트 또는 str 타입이 들어옴
deq = deque([])

# push
deq.append(n)
deq.appendleft(n)

# pop
deq.pop()
deq.popleft()

# 확장
# 오른쪽으로 확장
deq = deq.extend(n)
# 왼쪽으로 확장
deq = deq.extendleft(n)

# 원판 회전
# 오른쪽으로 n칸 밀어서 맨 오른쪽 값을 왼쪽에 붙임
deq.rotate(1)
# 반대
deq.rotate(-1)
```

## 딕셔너리

1. 딕셔너리 생성
2. 합치기
```python
d = {} # or dict()
d1.update(d2) # 합집합
```
3. 추가하기
4. 값 변경하기
```python
d['b'] = 4
d['b'] = 5
```
5. 특정 값 찾기
6. 특정 값 찾을 때 없는 키에 대해 'None'을 반환
7. 사전의 키값만 얻기
8. 사전의 값 얻기
9. 사전의 모든 키와 값을 튜플로 묶어서 반환
```python
d['a']
d.get('a')
d.keys()
d.values()
d.items()
```
10. 특정 키값 삭제
11. 모두 삭제
```python
del d['d']
d.clear()
```

## 우선순위 큐
```python
import heapq
hq = []
# 원소 넣기
heapq.heappush(hq, item)
# 원소 빼기
heapq.heappop(hq)
# 반환하지 않고 접근하고 싶다면
heap[0]
# 리스트 x를 선형 시간으로 heap으로 변환
heapq.heapify(x)
```
- 기본적으로 heapq는 최소 힙 기준으로 만들어져 최대 힙을 구현하기 위해서는 다음과 같이 (-1)을 곱한다.
```python
heapq.heappush(hq, -item)
heapq.heappop(hq, -item)
```







