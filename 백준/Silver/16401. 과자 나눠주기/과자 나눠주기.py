# 과자 나눠주기
def cntNephew(length, snacks):
    cnt = 0
    for snack in snacks:
        cnt += snack // length
    
    return cnt 

    
# 최대 길이 -> upper bound
# 막대과자의 길이가 mid일 때 나눠줄 수 있는 최대 조카의 수 탐색
def binary_search(left, right, target, snacks):
    while(left <= right):
        mid = (left + right) // 2
        nephew_cnt = cntNephew(mid, snacks)
        
        if nephew_cnt < target: # 나눠줄 수 있는 조카의 수가 찾고자 하는 값보다 작으면 -> 길이 줄이기
            right = mid - 1  
        else:
            left = mid + 1            
    
    return left - 1
    

m, n = map(int, input().split()) # 조카의 수, 과자의 수
snacks = list(map(int, input().split())) # 과자의 길이

# 연산 
snacks.sort()
ans = binary_search(1, max(snacks), m, snacks)

# 출력
print(ans)
