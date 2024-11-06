from collections import deque

def compareWord(word, next):
    cnt = 0
    for i in range(len(word)):
        if word[i] != next[i]:
            cnt += 1
        
        if cnt > 1:
            return False
            
    return True
    
def bfs(begin, target, words):
    visited = {w : 0 for w in words}
    queue = deque()
    queue.append(begin)
    visited[begin] = 1
    
    while queue:
        word = queue.popleft()
        for next in words:
            if not visited[next] and compareWord(word, next):
                visited[next] = visited[word] + 1
                queue.append(next)     
    
    return visited[target] - 1

def solution(begin, target, words):
    answer = 0
    
    if target in words:
        answer = bfs(begin, target, words)
    
    return answer