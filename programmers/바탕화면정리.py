def solution(wallpaper):
    row_len = len(wallpaper)
    col_len = len(wallpaper[0])
    answer = [row_len, col_len, 0, 0]
    for row_index in range(row_len):
        for col_index in range(col_len):
            if wallpaper[row_index][col_index] == '#':
                if row_index < answer[0]:
                    answer[0] = row_index
                if col_index < answer[1]:
                    answer[1] = col_index
                if row_index + 1 > answer[2]:
                    answer[2] = row_index + 1
                if col_index + 1 > answer[3]:
                    answer[3] = col_index + 1
    return answer
