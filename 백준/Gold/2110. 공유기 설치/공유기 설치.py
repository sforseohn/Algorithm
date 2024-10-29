# 공유기 설치
import sys
input = sys.stdin.readline

# 입력
n, c = map(int, input().split()) # 집, 공유기의 수
x = [0] * n
for i in range(n):
    x[i] = int(input())
      
# 연산
x.sort()
ans = 0
start = 1          # 최소 거리
end = x[-1] - x[0] # 최대 거리

# 탐색할 것: 최소 거리
while start <= end:
    mid = (start + end) // 2
    cur = x[0] # 공유기가 현재 설치된 위치
    cnt = 1    # 현재까지 설치된 공유기 수, 첫번째 집에는 설치
    
    for i in range(1, len(x)):
        if x[i] >= cur + mid: # 최소 거리 조건을 만족하면
            cnt += 1
            cur = x[i]
            
    if cnt >= c: # 공유기를 모두 설치했으면 답 갱신
        start = mid + 1
        ans = mid
    else:
        end = mid - 1

# 출력
print(ans)