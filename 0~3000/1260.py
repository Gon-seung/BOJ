import sys
from collections import deque


def bfs(start, n):
    visited_info = [True for _ in range(n)]
    visited_info[start] = False
    info = deque([start])
    answer = [start + 1]
    while info:
        pos = info.popleft()
        for i in map_info[pos]:
            if visited_info[i]:
                visited_info[i] = False
                info.append(i)
                answer.append(i + 1)
    return answer


def dfs(start, n):
    visited_info = [True for _ in range(n)]
    visited_info[start] = False
    info = [start]
    answer = [start + 1]
    while info:
        pos = info[-1]
        for i in map_info[pos]:
            if visited_info[i]:
                visited_info[i] = False
                info.append(i)
                answer.append(i + 1)
                break
        if info[-1] == pos:
            info.pop()
    return answer


n, m, v = list(map(int, sys.stdin.readline().split()))
map_info = [[] for _ in range(n)]
for i in range(m):
    a, b = list(map(int, sys.stdin.readline().split()))
    a -= 1
    b -= 1
    map_info[a].append(b)
    map_info[b].append(a)
map_info = list(map(sorted, map_info))
answer1 = dfs(v - 1, n)
print(' '.join(map(str, answer1)))
answer2 = bfs(v - 1, n)
print(' '.join(map(str, answer2)))



