import sys
input = sys.stdin.readline

SIZE = 9

def get_3x3(r, c):
    return (r // 3) * 3 + (c // 3)
    
def fill_sudoku(n, board):
    if n == len(to_fill):
        return True
    
    r, c = to_fill[n]
    for i in range(1, SIZE + 1): # i: 채울 수
        box = get_3x3(r, c)
        # 이미 있으면 건너뛰기
        if is_row[r][i] or is_col[c][i] or is_3x3[box][i]:
            continue
        
        # 채우기
        board[r][c] = i
        is_row[r][i] = True
        is_col[c][i] = True
        is_3x3[box][i] = True
        
        # 다음 탐색
        if fill_sudoku(n + 1, board):
            return True
        
        # 반납
        board[r][c] = 0
        is_row[r][i] = False
        is_col[c][i] = False
        is_3x3[box][i] = False 
    
    return False   
    
# 입력
board = []
for _ in range(SIZE):
    board.append([int(num) for num in input().strip()])

# 연산
is_row = [[False] * (SIZE+1) for _ in range(SIZE)]
is_col = [[False] * (SIZE+1) for _ in range(SIZE)]
is_3x3 = [[False] * (SIZE+1) for _ in range(SIZE)]
to_fill = []

for r in range(SIZE):
    for c in range(SIZE):
        num = board[r][c]
        if not num:
            to_fill.append([r, c])
        else:
            is_row[r][num] = True
            is_col[c][num] = True
            is_3x3[get_3x3(r, c)][num] = True

fill_sudoku(0, board)
        
# 출력
answer = ''
for i in range(SIZE):
    answer += ''.join(map(str,board[i]))
    answer += '\n'
print(answer)