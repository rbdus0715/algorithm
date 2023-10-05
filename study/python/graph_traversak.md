# 그래프 탐색 DFS, BFS

## 입력
```python
from sys import stdin
n, m, s = map(int, input().split())
node = [[] for i in range(n+1)]
for i in range(m):
    x, y = map(int, stdin.readline().split())
    node[x].append(y)
    node[y].append(x)
```

## 깊이 우선 탐색 DFS 그래프 순회
```python
import sys
sys.setrecursionlimit(150000)
visited = [0 for i in range(n+1)]

def dfs(s):
    visited[s] = True
    print(s, end=' ')
    for x in node[s]:
        if not visited[x]: dfs(x)

dfs(s)
```

## 넓이 우선 탐색 BFS 그래프 순회
```python
from collections import deque
visited = [0 for i in range(n+1)]
que = deque([])
def bfs(s):
    visited[s] = True
    print(s, end=' ')
    que.append(s)
    while len(que):
        u = que.popleft()
        for x in node[u]:
            if not visited[x]:
                visited[x] = True
                print(x, end=' ')
                que.append(x)
bfs(s)
```
