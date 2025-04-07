dx = [1, 0, -1, 0]
dy = [0, 1, 0, -1]

def dfs(start_x, start_y):
    global cnt
    visited[start_x][start_y] = True
    cnt += 1

    for i in range(4):
        nx = start_x + dx[i]
        ny = start_y + dy[i]

        if 0 <= nx < n and 0 <= ny < n and not visited[nx][ny] and graph[nx][ny] == 1:
            visited[nx][ny] = True
            dfs(nx, ny)


n = int(input())
graph = [list(map(int, input())) for _ in range(n)]
visited = [[False] * n for _ in range(n)]

house_counts = []
cnt = 0
for i in range(n):
    for j in range(n):
        if not visited[i][j] and graph[i][j] == 1:
            dfs(i, j)
            house_counts.append(cnt)
            cnt = 0

print(len(house_counts))
for house_cnt in sorted(house_counts):
    print(house_cnt)