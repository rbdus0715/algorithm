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
