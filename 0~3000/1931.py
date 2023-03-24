import sys

n = int(sys.stdin.readline())
info = []
for i in range(n):
    start, end = map(int, sys.stdin.readline().split())
    info.append([start, end])
info = sorted(info, key=lambda x: (x[1], x[0]))
end_time = 0
answer = 0
for start, end in info:
    if start >= end_time:
        answer += 1
        end_time = end
print(answer)
