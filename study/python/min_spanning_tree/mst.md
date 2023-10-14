# 최소 스패닝 트리
## 크루스칼 알고리즘
- 탐욕법과 유니온파인드를 혼합하여 사용
- 가장 가중치가 작은 간선부터 사이클이 생기지 않는 한에서 추가
- 사이클이 생기는지 확인은 union-find를 통해 확인

**예시(1) 가중치가 모두 1인 그래프에서 최소 스패닝 트리 찾기 [백준 1197](https://www.acmicpc.net/problem/1197)**
- 가중치가 주어진다면 ans+=1을 해당 간선의 w로 대신해서 ans+=w 하면 됨
#### 풀이1
```python
def find(x):
    if parent[x] != x:
        parent[x] = find(parent[x])
    return parent[x]

def merge(x, y):
    x = find(x)
    y = find(y)
    if x!=y:
        parent[y] = x


for _ in range(int(input())):
    
    n, m = map(int, input().split())
    
    parent = [i for i in range(n+1)]
    
    ans = 0
    for i in range(m):
        x, y = map(int, input().split())
        if find(x) == find(y):
            continue
        merge(x, y)
        ans += 1
    
    print(ans)
```
#### 풀이2
가중치가 모두 1인 최소 스패닝 트리의 간선 개수는 V-1개이다.

