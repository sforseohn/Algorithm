# 그룹 단어 체커
import sys
input = sys.stdin.readline

# 입력
n = int(input()) # 단어의 개수

# 연산
cnt = 0
for i in range(n):
    word = input().strip()
    visited = dict()
    visited[word[0]] = True
    
    if len(word) == 1:
        cnt += 1
        continue
    
    for j in range(1, len(word)):
        w = word[j]
        
        if w in visited:  # 이미 딕셔너리에 저장되어 있으면 = 이미 나타난 적 있으면
            if word[j-1] != w: # 앞 문자와 이어지는지 확인
                break
        else:
            visited[w] = True
            
        if j == len(word) - 1:
            cnt += 1

# 출력
print(cnt)