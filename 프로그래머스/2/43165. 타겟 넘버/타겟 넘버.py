cnt = 0

def dfs(cur_sum, idx, numbers, target):
    global cnt
    if idx == len(numbers) - 1:
        if cur_sum == target:
            cnt += 1
        return
    
    dfs(cur_sum + numbers[idx+1], idx + 1, numbers, target)
    dfs(cur_sum - numbers[idx+1], idx + 1, numbers, target)

def solution(numbers, target):
    answer = 0
    
    dfs(numbers[0], 0, numbers, target)
    dfs(-numbers[0], 0, numbers, target)
    
    return cnt