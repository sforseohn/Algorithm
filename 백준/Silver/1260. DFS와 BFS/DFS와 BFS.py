from collections import deque

def dfs(start):
    visited[start] = True
    print(start, end = ' ')
    for next_node in sorted(graph[start]):
        if not visited[next_node]:
            dfs(next_node)


def bfs(start):
    queue = deque([start])
    visited[start] = True

    while queue:
        node = queue.popleft()
        print(node, end = ' ')
        for next_node in graph[node]:
            if not visited[next_node]:
                visited[next_node] = True
                queue.append(next_node)


# 정점 개수, 간선 개수, 탐색을 시작할 정점 번호
n, m, v = map(int, input().split())

graph = [[] for _ in range(n + 1)]
for i in range(m):
    a, b = map(int, input().split())
    graph[a].append(b) # 양방향 연결
    graph[b].append(a)

for nodes in graph:
    nodes.sort()

visited = [False] * (n + 1)
dfs(v)
print()

visited = [False] * (n + 1)
bfs(v)

