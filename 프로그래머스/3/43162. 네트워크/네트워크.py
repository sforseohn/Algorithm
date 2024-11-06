visited = []
networks = []

def dfs(c):
    global visited, networks
    
    for i in range(len(networks)):
        if i != c and networks[c][i] and not visited[i]:
            visited[i] = True
            dfs(i)

def solution(n, computers):
    global visited, networks
    answer = 0
    visited = [False] * n
    networks = computers[:]
    
    for i in range(n):
        if not visited[i]:
            visited[i] = True
            answer += 1
            dfs(i)
    
    return answer