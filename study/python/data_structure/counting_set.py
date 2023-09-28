# 백준 10816 문제처럼
# 여러 개의 숫자가 주어지고 각 수가 몇 개 들어있는지 알려주는 사전 만들기



# 첫 번째 방법
# 접근 : 입력받은 숫자를 담은 배열을 이진 탐색을 통해 원하는 값을 찾아 카운트 하는 방법
# 실패 : 시간초과



# 두 번째 방법
# 접근 : bisect
# bisect 파이썬 내장 이진탐색 모듈
# bisect_left(list, value) : list에서 value가 왼쪽에서 몇 번째 인덱스인지
# bisect_right(list, value) : 오른쪽에서 몇 번재 인덱스인지
```python
from bisect import bisect_left, bisect_right

# 입력받은 배열 정렬
arr.sort()

# 원소 value가 몇 개 들어있는지 확인하는 함수
def count_by_range(arr, value):
  right_index = bisect_right(arr, value)
  left_index = bisect_left(arr, value)
  return right_index - left_index
```



# 세 번째 방법
# 접근 : Counter
# Counter : 리스트를 전달하면 해당 원소들이 몇 번 등장했는지 세서 딕셔너리 형태로 반환
```python
from collections import Counter
arr = [...]
count = Counter(arr)

# 숫자 n이 몇 번 들어있는지 확인하는 방법
num = count[n]
```


# 네 번째 방법
# 접근 : 해쉬맵 (파이썬에서는 딕셔너리)
```python
hash = {}

for i in arr:
  if i in hash:
    hash[i] += 1
  else:
    hash[i] = 1

for i in test:
  if i in hash:
    print(hash[i], end=' ')
  else:
    print(0, end=' ')
```
