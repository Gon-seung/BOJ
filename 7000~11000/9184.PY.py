import sys


def find_value(value_info, a, b, c):
    if value_info[a][b][c] != -1:
        return value_info[a][b][c]
    elif a == 0 or b == 0 or c == 0:
        value_info[a][b][c] = 1
    elif a == 21 or b == 21 or c == 21:
        value_info[a][b][c] = find_value(value_info, 20, 20, 20)
    elif a < b < c:
        value_info[a][b][c] = find_value(value_info, a, b, c - 1) + find_value(value_info, a, b - 1, c - 1) - find_value(value_info, a, b - 1, c)
    else:
        value_info[a][b][c] = find_value(value_info, a - 1, b, c) + find_value(value_info, a - 1, b - 1, c) + find_value(value_info, a - 1, b, c - 1) - find_value(value_info, a - 1, b - 1, c - 1)
    return value_info[a][b][c]


value_info = [[[-1 for _ in range(22)] for _ in range(22)] for _ in range(22)]
while True:

    a, b, c = map(int, sys.stdin.readline().split())
    ori_a, ori_b, ori_c = str(a), str(b), str(c)
    if a == -1 and b == -1 and c == -1:
        break

    if a <= 0 or b <= 0 or c <= 0:
        if a <= 0:
            a = 0
        if b <= 0:
            b = 0
        if c <= 0:
            c = 0
    if a > 20 or b > 20 or c > 20:
        if a > 20:
            a = 21
        if b > 20:
            b = 21
        if c > 20:
            c = 21
    answer = find_value(value_info, a, b, c)
    answer = str(answer)
    print("w(" + ori_a + ", " + ori_b + ", " + ori_c + ") = " + answer)
    #print(value_info[20][20][20])
