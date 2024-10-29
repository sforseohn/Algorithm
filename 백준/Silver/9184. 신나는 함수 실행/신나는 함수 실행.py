MAX_NUM = 20

def dp():
    for i in range(MAX_NUM + 1):
        for j in range(MAX_NUM + 1):
            for k in range(MAX_NUM + 1):
                if w[i][j][k]:
                    continue
                
                if i == 0 or j == 0 or k == 0:
                    w[i][j][k] = 1
                    continue
                    
                if i < j and j < k:
                    w[i][j][k] = w[i][j][k-1] + w[i][j-1][k-1] - w[i][j-1][k]
                else:
                    w[i][j][k] = w[i-1][j][k] + w[i-1][j-1][k] + w[i-1][j][k-1] - w[i-1][j-1][k-1]


w = [[[0] * (MAX_NUM+1) for _ in range(MAX_NUM+1)] for _ in range(MAX_NUM+1)]
dp()

while(True):
    a, b, c = map(int, input().split())
    if a == b == c == -1:
        break
    
    print('w(' + str(a) + ', ' + str(b) + ', ' + str(c) + ') = ', end='')
    if min(a, b, c) <= 0:
        print(1)
    elif max(a, b, c) > 20:
        print(w[MAX_NUM][MAX_NUM][MAX_NUM])
    else:
        print(w[a][b][c])