from collections import deque

dx = [-1, 1, 0, 0, 0, 0]
dy = [0, 0, -1, 1, 0, 0]
dz = [0, 0, 0, 0, -1, 1]

# 범위 확인
def check_range(z, x, y):
    if 0 <= x < n and 0 <= y < m and 0 <= z < h:
        return True
    return False


def check_finish():
    for i in range(h):
        for j in range(n):
            for k in range(m):
                if graph[i][j][k] == 0:
                    return False
    return True


def bfs(queue):
    time = 1

    while queue:
        z, x, y = queue.popleft()

        for i in range(6):
            nz = z + dz[i]
            nx = x + dx[i]
            ny = y + dy[i]

            if not check_range(nz, nx, ny):
                continue

            if graph[nz][nx][ny] != 0 and graph[nz][nx][ny] <= graph[z][x][y] + 1:
                continue

            graph[nz][nx][ny] = graph[z][x][y] + 1
            time = graph[nz][nx][ny]
            queue.append((nz, nx, ny))

    return time - 1


def end_search():
    print(-1)
    exit(0)


# 입력
m, n, h = map(int, input().split())
graph = [[[] for _ in range(n)] for _ in range(h)]
graph_sum = 0
queue = deque()

for i in range(h):
    for j in range(n):
        graph[i][j] = list(map(int, input().split()))
        graph_sum += sum(graph[i][j])

        for k in range(m):
            graph_sum += graph[i][j][k]
            if graph[i][j][k] == 1:
                queue.append((i, j, k))

if graph_sum == 0:
    end_search()

time = bfs(queue)

if not check_finish():
    end_search()

print(time)
