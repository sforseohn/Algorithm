from collections import deque
import heapq

EMPTY = 0
SHARK = 9

dx = [-1, 0, 0, 1]
dy = [0, -1, 1, 0]

def check_range(x, y):
    return 0 <= x < n and 0 <= y < n


def bfs(start_x, start_y, shark_size):
    visited = [[-1] * n for _ in range(n)]
    pq = []
    queue = deque([(start_x, start_y)])
    visited[start_x][start_y] = 0
    min_distance = float('inf')

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]

            # 지나갈 수 없는 경우 제외
            if not check_range(nx, ny) or space[nx][ny] > shark_size or space[nx][ny] == SHARK or visited[nx][ny] != -1:
                continue

            visited[nx][ny] = visited[x][y] + 1

            if visited[nx][ny] > min_distance:
                continue

            queue.append((nx, ny))

            if EMPTY < space[nx][ny] < shark_size:
                min_distance = visited[nx][ny]
                heapq.heappush(pq,(visited[nx][ny], nx, ny))

    if pq:
        distance, x, y = heapq.heappop(pq)
        return x, y, distance

    return -1, -1, -1


def move_shark(shark_x, shark_y):
    total_time = 0
    shark_size = 2
    fish_count = 0

    while True:
        # 먹을 물고기 정하기
        nx, ny, time = bfs(shark_x, shark_y, shark_size)

        # 먹을 물고기가 없으면 종료
        if nx == ny == -1:
            break

        # 이동, 시간 증가
        space[shark_x][shark_y] = 0
        shark_x, shark_y = nx, ny
        space[shark_x][shark_y] = 9
        total_time += time

        # 물고기 먹기, 상어 크기 증가
        fish_count += 1
        if fish_count == shark_size:
            shark_size += 1
            fish_count = 0

    return total_time


# 입력
n = int(input())
space = [list(map(int, input().split())) for _ in range(n)]

shark_x, shark_y = 0, 0
for i in range(n):
    for j in range(n):
        if space[i][j] == SHARK:
            shark_x, shark_y = i, j

print(move_shark(shark_x, shark_y))
