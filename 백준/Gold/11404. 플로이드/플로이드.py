INF = 1e9

def floyd():
    for k in range(n): # k: 거쳐가는 도시
        for i in range(n): # 시작
            for j in range(n): # 끝
                cost[i][j] = min(cost[i][j], cost[i][k] + cost[k][j])


n = int(input())
m = int(input())
cost = [[INF] * n for _ in range(n)]

for i in range(n):
    cost[i][i] = 0

for _ in range(m):
    start, end, c = map(int, input().split())
    cost[start - 1][end - 1] = min(cost[start - 1][end - 1], c)

floyd()

for i in range(n):
    for j in range(n):
        if cost[i][j] == INF:
            cost[i][j] = 0
        print(cost[i][j], end=' ')
    print()