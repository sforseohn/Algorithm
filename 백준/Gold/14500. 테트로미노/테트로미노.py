import sys
input = sys.stdin.readline
sys.setrecursionlimit(10 ** 6)
visited = []
board = []
dr = [(-1, 0), (1, 0), (0, -1), (0, 1)] 
TETRO = 4
ans = 0
max_val = 0

def backtrack(cnt, n, m, x, y, num):
    global ans, max_val
    
    if num + max_val * (TETRO - cnt) <= ans:
        return      
    
    if cnt == TETRO:
        ans = max(ans, num)
        return
    
    for dx, dy in dr:
        nx = x + dx
        ny = y + dy
        
        if nx >= 0 and nx < n and ny >= 0 and ny < m and not visited[nx][ny]:
            if cnt == 2:
                visited[nx][ny] = 1
                backtrack(cnt + 1, n, m, x, y, num + board[nx][ny])
                visited[nx][ny] = 0    
            
            visited[nx][ny] = 1
            backtrack(cnt + 1, n, m, nx, ny, num + board[nx][ny])
            visited[nx][ny] = 0    
    
    
def solution(n, m, board_input):
    global visited, board, ans, max_val
    visited = [[0] * m for _ in range(n)]
    board = board_input
    max_val = max(map(max, board))
    
    for i in range(n):
        for j in range(m):
            if not visited[i][j]:
                visited[i][j] = 1
                backtrack(1, n, m, i, j, board[i][j])
                visited[i][j] = 0
    
    return ans
    
    
if __name__ == "__main__":
    N, M = map(int, input().split())
    board = [list(map(int, input().split())) for _ in range(N)] 
    
    ans = solution(N, M, board)
    print(ans)