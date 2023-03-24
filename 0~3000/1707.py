import sys
from collections import deque


def start_bfs(pos):
    pos_info = deque([pos])
    type_info[pos] = 1
    while pos_info:
        pos = pos_info.popleft()
        type_value = type_info[pos]
        for i in map_info[pos]:
            if type_info[i] == type_value:
                return False
            elif type_info[i] == 0:
                type_info[i] = -type_value
                pos_info.append(i)
    return True


k = int(sys.stdin.readline())
for _ in range(k):
    answer = True
    v, e = list(map(int, sys.stdin.readline().split()))
    type_info = [0 for _ in range(v)]
    map_info = [[] for _ in range(v)]
    for i in range(e):
        a, b = map(lambda x: int(x) - 1, sys.stdin.readline().split())
        map_info[a].append(b)
        map_info[b].append(a)
    for i in range(v):
        if not type_info[i]:
            if not start_bfs(i):
                answer = False
                break
    if answer:
        print("YES")
    else:
        print("NO")


