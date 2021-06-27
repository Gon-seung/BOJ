
import sys

input = sys.stdin.readline().split()
N = int(input[0])
M = int(input[1])
memory = sys.stdin.readline().split()
cost = sys.stdin.readline().split()

maxcost = 10001
for i in range(N):
    memory[i] = int(memory[i])
    cost[i] = int(cost[i])
    #maxcost += cost[i]

data = [[0 for _ in range(maxcost + 1)] for _ in range(N + 1)]

for i in range(N):
    x, c = memory[i], cost[i]
    for j in range(maxcost):
        if (j >= c):
            data[i + 1][j] = max(data[i][j - c] + x, data[i][j])
        else:
            data[i + 1][j] = data[i][j]




answer = -1
for i in range(maxcost):
    if(data[-1][i] >= M):
        answer = i
        break
print(answer)