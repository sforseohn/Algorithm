def solution(n, lost, reserve):
    answer = 0
    
    clothes = [1] * n
    
    for i in range(1, n+1):
        if i in lost:
            clothes[i-1] -= 1
        if i in reserve:
            clothes[i-1] += 1
    
    for i in range(n):
        if not clothes[i]:
            # 먼저 앞에서 가져오기
            if i > 0 and clothes[i-1] > 1:
                clothes[i-1] -= 1
                clothes[i] += 1
            # 뒤에서 가져오기
            elif i < n-1 and clothes[i+1] > 1:
                clothes[i+1] -= 1
                clothes[i] += 1

        if clothes[i]:
            answer += 1
            
    return answer