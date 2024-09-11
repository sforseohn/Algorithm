n = int(input())
a = list(map(int, input().split()))
x = int(input())

a.sort()

cnt = 0
left, right = 0, n-1

while(left < right):
    add = a[left] + a[right]
    if add == x:
        cnt += 1
        left += 1
        right -= 1
    elif add < x:
        left += 1
    else:
        right -= 1

print(cnt)