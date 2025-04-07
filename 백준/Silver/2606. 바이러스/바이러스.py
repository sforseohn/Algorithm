# 바이러스 - DFS
import sys
sys.setrecursionlimit(10 ** 6)
input = sys.stdin.readline

def dfs(r):
    global cnt
    visited[r] = 1
    cnt += 1
    
    for i in range(n+1):
        if not visited[i] and graph[r][i]:
            dfs(i)
    
    
# 입력
n = int(input()) # 컴퓨터의 수
m = int(input()) # 연결된 쌍의 수

# 간선 (1, n)
graph = [[0] * (n+1) for _ in range(n+1)]

# 방문 체크
visited = [0] * (n+1)

# 양방향 연결
for _ in range(m): 
    u, v = map(int, input().split())
    graph[u][v] = graph[v][u] = 1

# 연산
cnt = -1 # 1번 컴퓨터는 제외
dfs(1)

# 출력
print(cnt)