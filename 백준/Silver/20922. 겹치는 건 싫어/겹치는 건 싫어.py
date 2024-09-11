n, k = map(int, input().split())
a = list(map(int, input().split()))

left, right = 0, 0
seen = dict()
max_len = 1

while(right < n):
    new = a[right]
    if new not in seen:
        seen[new] = 1
    else:
        seen[new] += 1
        # 겹치는 숫자가 k개 이상이면 겹치지 않을 때까지 왼쪽 포인터 증가 
        while(seen[new] > k and left <= right):
            to_remove = a[left]
            seen[to_remove] -= 1
            left += 1
            
            if to_remove == a[right]:
                break        
    
    max_len = max(max_len, right - left + 1)
    right += 1
        
print(max_len)