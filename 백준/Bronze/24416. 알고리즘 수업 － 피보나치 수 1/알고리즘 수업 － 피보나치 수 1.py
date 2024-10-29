import sys
input = sys.stdin.readline

def fibonacci_recursive(n):
    f = [0] * (n+1)
    
    f[1] = f[2] = 1
    for i in range(3, n+1):
        f[i] = f[i-1] + f[i-2]
        
    return f[n] 

def fibonacci_dp(n):
    return n-2
   
n = int(input().strip())

recur_cnt = fibonacci_recursive(n)
dp_cnt = fibonacci_dp(n)

print(recur_cnt, dp_cnt)