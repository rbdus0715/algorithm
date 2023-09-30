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
1. knight's tour | [문제](https://www.geeksforgeeks.org/the-knights-tour-problem/?ref=lbp) | [풀이](https://github.com/rbdus0715/algorithm/blob/main/study/python/back_tracking/knights_tour.py)
  - 백트래킹이 knight's tour problem을 푸는 가장 좋은 방법인건 아님. 휴리스틱한 방법이 더 좋은 성능을 보일 수 있음.
2. rat in maze | [문제](https://www.geeksforgeeks.org/rat-in-a-maze/?ref=lbp) | [풀이](https://github.com/rbdus0715/algorithm/tree/main/study/python/back_tracking)
  - 앞선 문제와 달리 2차원 배열 하나를 더 사용했다. maze 배열은 미로 확인용, curState는 지금 내가 가는 경로 체크용
3. N-queen problem | [문제](https://www.geeksforgeeks.org/n-queen-problem-backtracking-3/?ref=lbp) | [풀이](https://github.com/rbdus0715/algorithm/blob/main/study/python/back_tracking/n_queen.py)
  - 퀸의 대각선 방향도 모두 확인하는 isPossible 함수 구현이 까다로웠던 문제 
