# 서로소 집합 자료구조 (union-find)
- 서로소 부분집합들로 나누어진 원소들의 데이터를 처리하기 위한 자료구조!
- 두 가지 종류의 연산을 지원한다.
  - 합집합 (union) : 두 개의 원소가 포함된 집합을 하나의 집합으로 합치는 연산
  - 찾기 (find) : 특정 원소가 속한 집합이 어떤 집합인지 알려주는 연산


## 입력 및 출력
```python
v, e = map(int, input().split())

# 부모 배열
parent = [0] * (v+1)

# 부모를 자기 자신으로 초기화
for i in range(1, v+1):
    parent[i] = i

for i in range(e):
    a, b = map(int, input().split())
    union_parent(parent, a, b)

# 각 원소가 속한 집합 출력
for i in range(1, v+1):
    print(find_parent(parent, i))

# 부모 배열 출력
for i in range(1, v+1):
    print(parent[i])
```


## 합집합 (작은 수를 우선적으로 부모로 설정한다고 가정)
```python
def find_parent(parent, x):
  if parent[x] != x:
    return find_parent(parent, parent[x])
  return x

def union_parent(parent, a, b):
  a = find_parent(parent, a)
  b = find_parent(parent, b)
  if a<b:
    parent[b] = a
  else:
    parent[a] = b
```
