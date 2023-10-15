# N-aray 트리

## (1) N-aray 트리 구현 방법
**(좋은) 방법 1**
```python
class Node:
    def __init__(self,data): 
        self.data=data 
        self.children=[]
```
**(효율적인) 방법 2**
- first child/next sibling 표현법
- 첫 번째 자식만 부모와 연결되어있고, 자식끼리는 자식끼리 연결되어있음
- 장점
  - 메모리 효율성
  - 이진 트리로 처리 가능
  
```python
class Node: 
    def __init__(self, data): 
        self.data = data 
        self.firstChild = None
        self.nextSibling = None
```

## (2) 순회하기
[중위 순회]() : 마지막 자식을 제외한 모든 자식을 방문한 다음, 루트, 마지막 자식을 재귀적으로 방문
```python
def inorder(self, node):
    if node == None:
        return
    
    total = len(node.children)
    for i in range(total-1):
        self.inorder(node.children[i])
    print(node.data, end=' ')
    self.inorder(node.children[total-1])
```
