import sys
input = sys.stdin.readline

# 입력
n = int(input()) # 사람의 수
p = list(map(int, input().split())) # 각 사람이 돈을 인출하는데 걸리는 시간

# 연산
p.sort()

total = 0
for i in range(n):
    total += p[i] * (n-i)

# 출력
print(total)