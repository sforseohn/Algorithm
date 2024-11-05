import math 

def solution(progresses, speeds):
    answer = []
    max_required = math.ceil((100 - progresses[0]) / speeds[0])
    cnt = 1
    
    for i in range(1, len(progresses)):
        required = math.ceil((100 - progresses[i]) / speeds[i])
        
        if required <= max_required:
            cnt += 1
        else:
            answer.append(cnt)
            max_required = required
            cnt = 1
            
    answer.append(cnt)

    return answer