# time이 mid일 때 최대 처리할 수 있는 사람 수 구하기
def cnt_people(mid, times):
    cnt = 0
    for t in times:
        cnt += mid // t
    return cnt

def binary_search(n, times):
    left = 0
    right = times[0] * n
    
    while(left <= right):
        mid = (left + right) // 2
        people = cnt_people(mid, times)
        
        if people >= n: # 처리할 수 있는 사람이 충분함 -> 시간 줄이기
            right = mid - 1
        else:
            left = mid + 1
    return left

def solution(n, times):
    answer = 0
    
    times.sort()
    
    answer = binary_search(n, times)
    
    return answer