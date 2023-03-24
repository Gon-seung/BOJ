import sys


def dfs():
    if len(answer) == m:
        print(' '.join(map(str, answer)))
        return answer
    for i in range(1, n+1):
        if not answer or answer[-1] < i:
            answer.append(i)
            dfs()
            answer.pop()


n, m = map(int, sys.stdin.readline().split())
answer = []
dfs()
