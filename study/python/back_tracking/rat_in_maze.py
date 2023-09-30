def isPossible(y, x):
    if x>=0 and y>=0 and x<n and y<n and maze[y][x]==1 and curState[y][x]==0:
        return True
    else:
        return False

# curState는 미로의 현 상황을 알려주는 인자
def solve(y, x, curState):
    if x==n-1 and y==n-1:
            return True
    for i in range(4):
        ny = y + dy[i]
        nx = x + dx[i]
        if isPossible(ny, nx):
            
            curState[ny][nx] = 1
            if solve(ny, nx, curState):
                return True
            curState[ny][nx] = 0

def printSol():
    for i in range(n):
        for j in range(n):
            print(curState[i][j], end=' ')
        print()


################## main ################## 

n = int(input())
maze = []
for i in range(n):
    maze.append(list(map(int, input().split())))


curState = [[0 for i in range(n)] for i in range(n)]

dy = [1, 0, 0, -1]
dx = [0, -1, 1, 0]

curState[0][0] = 1

solve(0, 0, curState)

printSol()
