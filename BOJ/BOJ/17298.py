import sys
from collections import deque

num = int(sys.stdin.readline())
data = sys.stdin.readline().split()
NGE = [-1 for i in range(len(data))]
for i in range(len(data)):
    data[i] = int(data[i])

store = deque()
for i in range(len(data)):
    while(len(store) > 0 and data[i] > store[-1][0]):
        pos = store[-1][1]
        NGE[pos] = data[i]
        store.pop()
    store.append([data[i], i])

for i in NGE:
    print(i, end = " ")
