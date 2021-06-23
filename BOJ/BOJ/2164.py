
from collections import deque
import sys

save = deque()
num = int(sys.stdin.readline())

data = list(range(1, num + 1))
data.reverse()
data = deque(data)

while(len(data) != 1):
    data.pop()
    move = data.pop()
    data.appendleft(move)
print(data[0])    