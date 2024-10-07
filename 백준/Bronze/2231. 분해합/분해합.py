# 입력
n = int(input())

# 연산
ans = 0
for i in range (1, n): # 1부터 n까지 반복
    num = i
    num += sum(map(int , str(i)))
    
    if n == num:
        ans = i
        break

# 출력
print(ans)