from collections import deque

def make_graph(n, edge):
    graph = [[] for _ in range(n + 1)]  # 인접 리스트로 변경

    for left, right in edge:
        graph[left].append(right)
        graph[right].append(left)
    
    return graph

def bfs(n, graph):
    max_cost = 0
    max_count = 0
    visited = [False] * (n + 1)  # 방문 여부를 True/False로 체크
    queue = deque([(1, 0)])  # (노드, 거리)로 시작
    
    visited[1] = True  # 시작 노드는 이미 방문
    
    while queue:
        node, cost = queue.popleft()
        
        # 최대로 갔을 때의 거리 갱신
        if cost > max_cost:
            max_count = 1
            max_cost = cost
        elif cost == max_cost:
            max_count += 1

        for neighbor in graph[node]:
            if not visited[neighbor]:
                visited[neighbor] = True
                queue.append((neighbor, cost + 1))  # 거리 1 증가시키면서 방문
    
    return max_count

def solution(n, edge):
    graph = make_graph(n, edge)
    answer = bfs(n, graph)
    return answer
