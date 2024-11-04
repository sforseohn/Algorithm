import sys
input = sys.stdin.readline

def binary_search(n, target, cards):
    left = 0
    right = n - 1
    
    while(left <= right):
        mid = (left + right) // 2
        if cards[mid] == target:
            return 1
        elif cards[mid] > target:
            right = mid - 1
        else:
            left = mid + 1
    return 0
    
    
# 입력
n = int(input())
cards = list(map(int, input().split()))
m = int(input())
to_check = list(map(int, input().split()))

cards.sort()

for x in to_check:
    result = binary_search(n, x, cards)
    print(result, end=' ')