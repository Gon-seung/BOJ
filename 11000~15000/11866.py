from collections import deque
import sys

input = sys.stdin.readline().split()
N = int(input[0])
K = int(input[1])
data = deque(range(1,N+1))
data.reverse()

answer = deque()
while(len(data) > 0):
    for i in range(K - 1):
        move = data.pop()
        data.appendleft(move)
    delete = data.pop()
    answer.append(delete)

print("<", end = "")
len = len(answer)
for i in range(len - 1):
    print(answer.popleft(), end = "")
    print(", ", end = "")
print(answer.popleft(), end = "")
print(">")