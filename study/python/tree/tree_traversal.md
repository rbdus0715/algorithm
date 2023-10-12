# 트리 순회

## 전위순회, 중위순회, 후위순회
[1991](https://www.acmicpc.net/problem/1991) 정답 코드
```python
class Node:
    def __init__(self, data, left_node, right_node):
        self.data = data
        self.left_node = left_node
        self.right_node = right_node

n = int(input())
tree = {}

for i in range(n):
    data, left_node, right_node = input().split()
    if left_node == '.':
        left_node = None
    if right_node == '.':
        right_node = None
    tree[data] = Node(data, left_node, right_node)

# 전위순회 : 루트를 먼저 방문
def pre_order(node):
    print(node.data, end='')
    if node.left_node != None:
        pre_order(tree[node.left_node])
    if node.right_node != None:
        pre_order(tree[node.right_node])

# 중위순회 : 왼쪽 자식을 방문한 후 루트를 방문
def in_order(node):
    if node.left_node != None:
        in_order(tree[node.left_node])
    print(node.data, end='')    
    if node.right_node != None:
        in_order(tree[node.right_node])

# 후위순회 : 왼쪽, 오른쪽 자식을 먼저 방문 후 루트를 방문
def post_order(node):
    if node.left_node != None:
        post_order(tree[node.left_node])
    if node.right_node != None:
        post_order(tree[node.right_node])
    print(node.data, end='')


pre_order(tree['A'])
print()
in_order(tree['A'])
print()
post_order(tree['A'])












```
