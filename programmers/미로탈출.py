def find_min_len(start, end, maps):
    len_info = [[0 for _ in range(len(maps[0]))] for _ in range(len(maps))]
    dis_info = [start]
    len_info[start[0]][start[1]] = 1
    move = [[0, -1], [0, 1], [1, 0], [-1, 0]]
    dis = 1
    while len(dis_info) > 0:

        new_dis_info = []
        for i, j in dis_info:
            for i_plus, j_plus in move:
                if 0 <= i + i_plus < len(maps) and 0 <= j + j_plus < len(maps[0]) and \
                        maps[i + i_plus][j + j_plus] != 'X' and len_info[i + i_plus][j + j_plus] == 0:
                    len_info[i + i_plus][j + j_plus] = dis
                    new_dis_info.append([i + i_plus, j + j_plus])
                    if [i + i_plus, j + j_plus] == end:
                        return dis
        dis_info = new_dis_info.copy()
        dis += 1
    return -1


def solution(maps):
    answer = 0
    for i in range(len(maps)):
        for j in range(len(maps[0])):
            if maps[i][j] == 'S':
                start = [i, j]
            if maps[i][j] == 'L':
                labber = [i, j]
            if maps[i][j] == 'E':
                end = [i, j]
    answer1 = find_min_len(start, labber, maps)
    if answer1 == -1:
        return -1
    answer2 = find_min_len(labber, end, maps)
    if answer2 == -1:
        return -1

    return answer1 + answer2
