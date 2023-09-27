import sys

A = [64, 25, 12, 22, 11]

for i in range(len(A)):
    
    min_idx = i
    
    # 최소 원소 찾기
    for j in range(i+1, len(A)):
        if A[min_idx] > A[j]:
            min_idx = j
    
    # 스와핑
    A[i], A[min_idx] = A[min_idx], A[i]
    
for i in range(len(A)):
    print(A[i], end=' ')
