graph = []
is_used = []
ans = []

def dfs(city, path):
    global graph, is_used, ans
    
    if len(path) == len(graph) + 1: # 경로 완성
        ans.append(path)
        return
    
    for i in range(len(graph)):
        start, end = graph[i]
            
        if start == city and not is_used[i]:
            is_used[i] = True
            dfs(end, path + [end])
            
            is_used[i] = False
    

def solution(tickets):  
    global graph, is_used, ans
    
    tickets.sort()
    graph = tickets[:]   
    is_used = [False] * len(tickets)
    
    dfs('ICN', ['ICN'])
    
    return ans[0]