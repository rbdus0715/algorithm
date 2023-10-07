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

## 벨만포드 알고리즘 [문제](https://www.acmicpc.net/problem/11657)
```python
import sys
input = sys.stdin.readline
INF = int(1e9)

def bf(start):
    dist[start] = 0
    for i in range(n):
        # 매 반복마다 모든 간선을 확인
        for j in range(m):
            cur = edges[j][0]
            next_node = edges[j][1]
            cost = edges[j][2]
            
            if dist[cur] != INF and dist[next_node] > dist[cur] + cost:
                dist[next_node] = dist[cur] + cost
               
                if i == n-1:
                    return True
                    
    return False

######## main ########

n, m = map(int, input().split())
edges = []
dist = [INF] * (n+1)

for _ in range(m):
    a, b, w = map(int, input().split())
    edges.append((a, b, w))

negative_cycle = bf(1)

if negative_cycle:
    print("-1")
else:
    for i in range(2, n+1):
        if dist[i] == INF:
            print("-1")
        else:
            print(dist[i])
```
