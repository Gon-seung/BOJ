import sys


def check_possible(new_x, new_y):
    for x, y in queen_poses:
        if new_x == x:
            return False
        if new_y == y:
            return False
        if abs(new_x - x) == abs(new_y - y):
            return False
    return True


def dfs(pos):
    answer = 0
    if len(queen_poses) == n:
        return 1
    for i in range(n):
        for j in range(n):
            if i * n + j >= pos and check_possible(i, j):
                queen_poses.append([i, j])
                answer += dfs(i * n + j)
                queen_poses.pop()
    return answer


n = int(sys.stdin.readline())
queen_poses = []
print(dfs(0))
