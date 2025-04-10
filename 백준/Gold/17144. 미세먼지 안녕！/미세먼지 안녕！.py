from collections import deque

PURIFIER = -1
CLOCKWISE = 1
COUNTER_CLOCKWISE = -1

# 동 북 서 남
dx = [0, -1, 0, 1]
dy = [1, 0, -1, 0]

def check_range(r, c):
    return 1 <= r <= size_r and 1 <= c <= size_c


def diffuse(r, c, to_add):
    diffuse_cnt = 0
    amount = room[r][c] // 5

    for i in range(4):
        nx = r + dx[i]
        ny = c + dy[i]

        # 확산
        if check_range(nx, ny) and room[nx][ny] != PURIFIER:
            to_add[nx][ny] += amount
            diffuse_cnt += 1

    to_add[r][c] -= amount * diffuse_cnt

    return to_add


def rotate(r, direction):
    # 동 북 서 남 (+1)
    if direction == CLOCKWISE:
        x, y = r - 1, 1
        d = 1
    else:
        x, y = r + 1, 1
        d = 3

    while (True):
        # 다음 인덱스 구하기
        if not check_range(x + dx[d], y + dy[d]):
            d = (d - direction) % 4
        elif direction == 1 and x + dx[d] > r:
            d = (d - direction) % 4
        elif direction == -1 and x + dx[d] < r:
            d = (d - direction) % 4

        x += dx[d]
        y += dy[d]

        if (x == r and y == 1): # 한 바퀴를 돌았으면
            room[x - dx[d]][y - dy[d]] = 0
            break

        room[x - dx[d]][y - dy[d]] = room[x][y]


def circulate(purifier_pos):
    # 위쪽 순환
    rotate(purifier_pos, 1)
    # 아래쪽 순환
    rotate(purifier_pos + 1, -1)


def monitor_room(r, c, t, purifier_pos):
    for _ in range(t):
        # 1. 미세먼지 확산
        to_add = [[0] * (size_c + 1) for _ in range(size_r + 1)]
        for i in range(1, r + 1):
            for j in range(1, c + 1):
                if room[i][j] > 0:
                    to_add = diffuse(i, j, to_add)
        # 변경된 양 반영
        for i in range(1, r + 1):
            for j in range(1, c + 1):
                room[i][j] += to_add[i][j]

        # 2. 공기청정기 작동
        circulate(purifier_pos)

# 입력
size_r, size_c, t = map(int, input().split())
room = [[0]]
for _ in range(size_r):
    room.append([0] + list(map(int, input().split())))

purifier_pos = 0
for i in range(1, size_r + 1):
    if room[i][1] == PURIFIER:
        purifier_pos = i
        break

monitor_room(size_r, size_c, t, purifier_pos)

total = 0
for row in room:
    total += sum(row)
print(total + 2) # 공기청정기 빼기