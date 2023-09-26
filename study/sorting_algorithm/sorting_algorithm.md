# 파이썬 정렬 (은정이를 위한)
****
- sort는 리스트.sort() 형식으로, 리스트 원본값을 직접 수정한다.
- sorted는 sorted(리스트) 형식으로, 원본값은 그대로이고 정렬값을 반환한다.
**오름차순**
list.sort(reverse=False)
**내림차순**
list.sort(reverse=True)
**lambda**
  
```python
## key 인자에 함수 넘겨주면 해당 함수의 반환값을 비교하여 순서대로 정렬한다.
# 문자열 길이 정렬
list.sort(key=lambda x : len(x))
# 튜플 리스트 두번째 요소에 대해 정렬
arr_sorted = sorted(arr, key=lambda x : x[1)
## 첫 번째 인자를 기준으로 오름차순, 두번째 기준으로 내림차순 정렬하면
arr_sorted = sorted(arr, key=lambda x : (x[0], -x[1]))
```
**딕셔너리 정렬**

(1) key 정렬
```python
d = {"dream": 0, "car": 99, "blockdmask": 1, "error": 30, "app": 20}
d_sorted = sorted(d.items())
# 정렬 이후 다시 dic으로 변환
dict_sorted = dict(d_sorted)
```
(2) value 정렬
```python
import operator
d_sorted = sorted(d.items(), key=operator.itemgetter(1))
# 아니면 아래 방법 사용
d_sorted = sorted(d.items(), key=lambda x : x[1])
# 내림차순은 reverse=True만 파라미터에 넣으면 됨
```
### 선택 정렬 (selection)
![image](https://github.com/rbdus0715/algorithm/assets/85426187/1584741b-b95a-44c4-88bd-0ced4ec48003)
### 버블 정렬
![image](https://github.com/rbdus0715/algorithm/assets/85426187/b9613e53-95a4-4236-963b-d86becc3af4a)
### 삽입 정렬
![image](https://media.geeksforgeeks.org/wp-content/uploads/insertionsort.png)
### 병합 정렬 (머지 소트)

### 퀵 정렬

### 힙 정렬

### 카운팅 정렬

### radix 정렬

### 버켓 정렬 (bucket sort)
