import sys
input = sys.stdin.readline

# upper bound
def binary_search(left, right, n, target, times):    
    ans = right
    while(left <= right):
        mid = (left + right) // 2
        people = 0
    
        for i in range(n):
            people += mid // times[i]
        
        if people >= target: # 현재 처리할 수 있는 사람의 수 >= target -> 시간을 줄여보자
            right = mid - 1
        else:
            left = mid + 1
            
    return left

n, m = map(int, input().split())
# m명의 사람이 심사를 받는 데 걸리는 시간의 최소 구하기
times = list()
for _ in range(n):
    times.append(int(input()))
    
times.sort()
  
ans = binary_search(times[0], times[n-1] * m, n, m, times)    
print(ans)