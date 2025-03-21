INF = 1000000007

def solution(m, n, puddles):
    dp = [[0] * (m + 1) for _ in range(n + 1)]
    dp[1][1] = 1
    
    for i in range(2, n + 1):
        if [1, i] not in puddles:
            dp[i][1] = dp[i - 1][1] % INF
            
    for j in range(2, m + 1):
        if [j, 1] not in puddles:
            dp[1][j] = dp[1][j - 1] % INF
            
    for i in range(2, n + 1):
        for j in range(2, m + 1):
            if [j, i] not in puddles:
                dp[i][j] = (dp[i - 1][j] + dp[i][j - 1]) % INF

    return dp[n][m]