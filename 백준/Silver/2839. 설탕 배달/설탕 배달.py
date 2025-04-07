n = int(input())

divisor = n // 5

# 5 * x + 3 * y
for x in range(divisor, -1, -1):
    left = n - x * 5
    if left % 3 == 0:
        y = left // 3
        print(x + y)
        exit(0)

print(-1)