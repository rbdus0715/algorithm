# 백트래킹 알고리즘
- 일종의 브루트포스 문제로, 재귀적인 성향을 띤다.
- 모든 경우의수를 탐색하는 동시에 맞지 않으면 바로 가지치기를 한다.

### 백트래킹 알고리즘의 형태
  ```python
# 이 솔루션이 맞는지
def isPossible(i):
    if:
      return True
    else:
      return False

def solve(check_board):
    # 재귀함수가 끝나는 조건
    if:
      return True
  
    # 다음 실행 가능한 경우를 모두 시도한다.
    for i in range():
      if isPossible(i):
        check_board[i] = True
        solve(check_board)
  
        ####### 백트래킹 #######
        check_board[i] = False
  
    return False
  ```

### 백트래킹 알고리즘의 실용성
- 대부분의 백트레킹 알고리즘은 동적 프로그래밍 또는 탐욕법으로 해결할 수 있다.
- 반면, 백트래킹으로밖에 풀지 못하는 문제도 있다.

### 유명 문제들
[link](https://www.geeksforgeeks.org/top-20-backtracking-algorithm-interview-questions/)