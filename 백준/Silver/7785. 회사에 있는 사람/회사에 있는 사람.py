import sys

# 입력 & 연산
n = int(sys.stdin.readline())
people = {}

for _ in range(n):
    p, message = sys.stdin.readline().split()
    if message == 'enter':
        people[p] = 'e'
    elif people[p]:
        del people[p]

# 출력
for i in sorted(people,reverse=True):
    print(i)