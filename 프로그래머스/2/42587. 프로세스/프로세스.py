def solution(priorities, location):
    queue = priorities[:]
    cnt = 0
    
    while(True):
        front = queue.pop(0)
        if not queue:
            return cnt + 1
        
        if max(queue) <= front:
            cnt += 1
            if location == 0:
                return cnt
        else:
            queue.append(front)
            
        location = (location - 1) % len(queue)