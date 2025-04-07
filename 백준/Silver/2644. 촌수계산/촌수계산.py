from collections import deque

def bfs(start, end):
    visited = [-1] * (n + 1)
    queue = deque([start])
    visited[start] = 0

    while queue:
        node = queue.popleft()

        for next_node in graph[node]:
            if visited[next_node] == -1:
                visited[next_node] = visited[node] + 1
                queue.append(next_node)

    return visited[end]


n = int(input())
graph = [[] for _ in range(n + 1)] # 인접 리스트

a, b = map(int, input().split())
m = int(input())

for _ in range(m):
    x, y = map(int, input().split())
    graph[x].append(y)
    graph[y].append(x)

print(bfs(a, b))