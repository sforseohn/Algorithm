import sys
input = sys.stdin.readline

SIZE = 100
board = [[0] * (SIZE+1) for _ in range(SIZE+1)] # 0 ~ 100
direcs = [(0, 1), (-1, 0), (0, -1), (1, 0)] # 우상좌하

def draw_curves(curves):
    for start_x, start_y, d, g in curves:
        x = start_x
        y = start_y
        board[y][x] = 1
        
        x += direcs[d][1]
        y += direcs[d][0]
        board[y][x] = 1
        
        directions = [d]
        
        for _ in range(g): # 각 세대마다 그리기
            cur_size = len(directions)
            
            for i in range(cur_size - 1, -1, -1):
                next_d = (directions[i] + 1) % 4
                x += direcs[next_d][1]
                y += direcs[next_d][0]
                board[y][x] = 1
                
                directions.append(next_d)
        
            
def cnt_squares(): 
    cnt = 0
    
    for i in range(SIZE):
        for j in range(SIZE):
            if board[i][j] and board[i+1][j] and board[i][j+1] and board[i+1][j+1]:
                cnt += 1
    
    return cnt
    
# 입력
n = int(input()) # 드래곤 커브의 수
# x와 y는 드래곤 커브의 시작 점, d는 시작 방향, g는 세대
curves = [list(map(int, input().split())) for _ in range(n)]

# 연산

# 드래곤 커브 그리기
draw_curves(curves)

# 정사각형 개수 찾기
# 크기가 1×1인 정사각형의 네 꼭짓점이 모두 드래곤 커브의 일부인 것의 개수를 출력
ans = cnt_squares()

# 출력
print(ans)

