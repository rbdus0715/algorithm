def isPossible(y, x):
    if x>=0 and y>=0 and x<n and y<n and board[y][x] == -1:
        return True
    else:
        return False

def printSol():
    for i in range(n):
        for j in range(n):
            print(board[i][j], end=' ')
        print()


# 파라미터로 pos가 들어감으로써 브레이크 장치를 준 것이 포인트
def solve(board, y, x, pos):
    if(pos == n**2):
        return True
    
    for i in range(8):
        ny = y + dy[i]
        nx = x + dx[i]
        if isPossible(ny, nx):
            board[ny][nx] = pos
            
            # 모든 경우의 수를 모두 탐색하지 않기 때문에 
            # 가능한 경우를 발견할 시 바로 True를 반환하고 종료한다.
            if solve(board, ny, nx, pos+1):
                return True
            
            # **백트래킹**
            board[ny][nx] = -1
            
    # 모든 경우의 수를 탐색해도 못 찾는 경우
    # False를 반환해주어 함수를 종료한다.
    return False



################## main ################## 

n = int(input())

board = [[-1 for i in range(n)] for i in range(n)]

dy = [1, 2, 2, 1, -1, -2, -2, -1]
dx = [2, 1, -1, -2, -2, -1, 1, 2]

# 현재 상황은 체크하고 들어가기
board[0][0] = 0
# counting
pos = 1

solve(board, 0, 0, pos)

printSol()

    
