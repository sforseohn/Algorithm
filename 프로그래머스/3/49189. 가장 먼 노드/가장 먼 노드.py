from collections import deque

def make_graph(n, edge):
    graph = [[] for _ in range(n + 1)] # 인접 리스트

    for left, right in edge:
        graph[left].append(right)
        graph[right].append(left)
    
    return graph

def bfs(n, graph):
    max_cost = 0
    max_count = 0
    visited = [False] * (n + 1)  
    queue = deque([(1, 0)]) 
    
    visited[1] = True 
    
    while queue:
        node, cost = queue.popleft()
        
        # 최대 거리 갱신
        if cost > max_cost:
            max_count = 1
            max_cost = cost
        elif cost == max_cost:
            max_count += 1

        for next in graph[node]:
            if not visited[next]:
                visited[next] = True
                queue.append((next, cost + 1)) 
    
    return max_count

def solution(n, edge):
    graph = make_graph(n, edge)
    answer = bfs(n, graph)
    return answer
