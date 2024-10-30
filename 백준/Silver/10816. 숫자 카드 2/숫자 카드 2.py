import sys
input = sys.stdin.readline

def find_lower(n, num):
    global cards
    left = 0
    right = n
    
    while(left < right): # left > right이면 break
        mid = (left + right) // 2

        if cards[mid] < num: # 찾고자 하는 수가 중간보다 큼 -> 중간보다 오른쪽에 있음 
            left = mid + 1
        else: 
            right = mid
            
    return left
    
def find_upper(n, num):
    global cards
    left = 0
    right = n
    
    while(left < right): # left > right이면 break
        mid = (left + right) // 2
                
        if cards[mid] <= num: # 찾고자 하는 수가 중간보다 큼 -> 중간보다 오른쪽에 있음 
            left = mid + 1
        else:
            right = mid
    
    return left
    
n = int(input()) # 숫자카드의 수
cards = list(map(int, input().split()))
m = int(input())
to_check = list(map(int, input().split()))

cards.sort()

for num in to_check:
    lower_bound = find_lower(n, num)
    upper_bound = find_upper(n, num)

    print(upper_bound - lower_bound, end = ' ')