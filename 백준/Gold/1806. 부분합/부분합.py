MAX_LEN = 100000

n, s = map(int, input().split())
nums = list(map(int, input().split()))

left, right = 0, 0
min_len = MAX_LEN
nums_sum = 0

while True:
    if nums_sum >= s:
        min_len = min(min_len,right-left)
        nums_sum -= nums[left]
        left +=1
    elif right == n:
        break
    else:
        nums_sum += nums[right]
        right += 1

if min_len == MAX_LEN:
    print(0)
else:
    print(min_len)
