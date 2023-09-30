def isPossible(row, col):
    
    for i in range(row):
        if board[i][col]:
            return False
    
    ### 중요 포인트 ###
    for i, j in zip(range(row, -1, -1), range(col, -1, -1)):
        if board[i][j]:
            return False
    
    for i, j in zip(range(row, -1, -1), range(col, n, 1)):
        if board[i][j]:
            return False

    return True


def solve(board, row):
    if row == n:
        return True
    
    for i in range(n):
        if isPossible(row, i):
            board[row][i] = 1
            if solve(board, row + 1):
                return True
            board[row][i] = 0
    
    return False

def printSol():
    for i in range(n):
        for j in range(n):
            print(board[i][j], end=' ')
        print()
        
        
################## main ################## 

n = int(input())

board = [[0 for i in range(n)] for i in range(n)]

if not solve(board, 0):
    print('solution does not exist')
else:
    printSol()
