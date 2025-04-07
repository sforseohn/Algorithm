from collections import deque

def bfs(n, m):
    dx = [0, 1, 0, -1]
    dy = [1, 0, -1, 0]
    queue = deque([(0, 0)])

    while queue:
        x, y = queue.popleft()

        # 도착
        if x == n - 1 and y == m - 1:
            return graph[n - 1][m - 1]

        for i in range(4):
            new_x = x + dx[i]
            new_y = y + dy[i]
            if 0 <= new_x < n and 0 <= new_y < m and graph[new_x][new_y] == 1:
                graph[new_x][new_y] = graph[x][y] + 1
                queue.append((new_x, new_y))

                
n, m = map(int, input().split())
graph = [list(map(int, input())) for _ in range(n)]

print(bfs(n, m))