def check_line(board, who):
    line_count = 0
    for i in range(3):
        check = True
        for j in range(3):
            if board[i][j] != who:
                check = False
        if check:
            line_count += 1
    for i in range(3):
        check = True
        for j in range(3):
            if board[j][i] != who:
                check = False
        if check:
            line_count += 1
    if board[0][0] == who and board[1][1] == who and board[2][2] == who:
        line_count += 1
    if board[2][0] == who and board[1][1] == who and board[0][2] == who:
        line_count += 1
    return line_count


def solution(board):
    o_count = 0
    x_count = 0
    for i in range(3):
        for j in range(3):
            if board[i][j] == 'O':
                o_count += 1
            elif board[i][j] == 'X':
                x_count += 1
    o_line = check_line(board, 'O')
    x_line = check_line(board, 'X')
    if o_count == x_count:
        if o_line > 0:
            return 0
        return 1
    elif o_count == x_count + 1:
        if x_line > 0:
            return 0
        return 1
    else:
        return 0