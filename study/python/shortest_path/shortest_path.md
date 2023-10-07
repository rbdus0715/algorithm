# 최단경로 알고리즘

## 다익스트라
```python
from sys import stdin
import heapq
from heapq import heappop, heappush
from math import inf

#### 입력 ####
v, e = map(int, input().split())
start = int(input())
node = [[] for i in range(v+1)]
for i in range(e):
    x, y, w = map(int, stdin.readline().split())
    node[x].append([y, w])

#### 다익스트라 ####
def dijkstra(start):
    pq = []
    d = [inf for nd in node]
    
    d[start] = 0
    heappush(pq, [0, start])
    
    while pq:
        curDistance, cur = heappop(pq)
        
        if d[cur] < curDistance:
            continue
        
        for new, newDistance in node[cur]:
            distance = curDistance + newDistance
            if distance < d[new]:
                d[new] = distance
                heappush(pq, [distance, new])

    return d

d = dijkstra(start)
for i in range(1, v+1):
    if d[i] == inf:
        print('INF')
    else: print(d[i])    
```

## 0-1 bfs
```python

```
