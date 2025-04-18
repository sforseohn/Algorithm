FLOWER_CNT = 3
total_price = 0
min_price = 200 * 10 * 10

def check_can_plant(i, j):
    for dx, dy in direction:
        nx = i + dx
        ny = j + dy

        if is_flower[nx][ny]:
            return False

    return True

def put_flower(i, j, put=True):
    global total_price
    for dx, dy in direction:
        nx = i + dx
        ny = j + dy

        if put:
            is_flower[nx][ny] = True
            total_price += price[nx][ny]
        else:
            is_flower[nx][ny] = False
            total_price -= price[nx][ny]


def seek(cnt):
    global total_price, min_price
    if cnt == FLOWER_CNT:
        min_price = min(min_price, total_price)
        return

    if total_price > min_price:
        return

    for i in range(1, n-1):
        for j in range(1, n-1):
            if check_can_plant(i, j):
                put_flower(i, j)

                seek(cnt + 1)

                put_flower(i, j, False)

n = int(input())
price = [list(map(int, input().split())) for _ in range(n)]
is_flower = [[False] * n for _ in range(n)]
direction = [[0, 0], [-1, 0], [1, 0], [0, -1], [0, 1]]

seek(0)

print(min_price)