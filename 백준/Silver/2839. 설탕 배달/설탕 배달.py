# 5 * x + 3 * y
n = int(input())

divisor = n // 5
cnt = 0
for i in range(divisor, -1, -1):
    cnt = i
    left = n - i * 5
    if left % 3 == 0:
        cnt += left // 3
        print(cnt)
        exit(0)

print(-1)