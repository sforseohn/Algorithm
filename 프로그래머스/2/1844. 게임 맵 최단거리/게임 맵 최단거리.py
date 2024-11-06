import collections

def bfs(start_x, start_y, maps):  
    n = len(maps)
    m = len(maps[0])
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    queue = collections.deque()
    queue.append((start_x, start_y))
    
    while queue:
        x, y = queue.popleft()
        
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            
            if 0 <= nx < n and 0 <= ny < m:
                if maps[nx][ny] == 1:        
                    maps[nx][ny] = maps[x][y] + 1
                    queue.append((nx, ny))      
                    
    return maps[n-1][m-1]

def solution(maps):    
    answer = bfs(0, 0, maps)
    
    if answer == 1:
        return -1
    
    return answer