from collections import deque 

def bfs(maps):
    n = len(maps)
    m = len(maps[0])
    queue = deque([(0, 0, 1)]) # 시작 위치, 거리
    
    dx = [-1, 1, 0, 0]
    dy = [0, 0, -1, 1]
    
    while queue:
        x, y, cost = queue.popleft()
        
        for i in range(len(dx)):
            new_x = x + dx[i]
            new_y = y + dy[i]

            # 범위 안에 있는지, 지나갈 수 있는지 체크
            if 0 > new_x or new_x >= n or 0 > new_y or new_y >= m:
                continue
                
            if not (maps[new_x][new_y] == 1 or maps[new_x][new_y] > cost + 1):
                continue
            
            if (new_x == n - 1 and new_y == m - 1):
                return cost + 1

            maps[new_x][new_y] = cost + 1
            queue.append((new_x, new_y, cost + 1))
    
    return -1
    

def solution(maps):
    answer = bfs(maps)
    return answer