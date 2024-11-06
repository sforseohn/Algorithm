def find_alpha_diff(a):
    return min(ord(a) - ord('A'), ord('Z') - ord(a) + 1)

def solution(name):    
    ans = 0
    n = len(name)
    min_moves = n - 1  # 최대 이동 거리
    
    for char in name:
        ans += find_alpha_diff(char)
    
    for i in range(n):
        idx = i + 1
        
        while idx < n and name[idx] == 'A':
            idx += 1
            
        min_moves = min(min_moves, i + n - idx + min(i, n - idx))

    return ans + min_moves