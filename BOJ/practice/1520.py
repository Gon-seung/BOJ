import sys
from collections import deque

n,m = map(int,sys.stdin.readline().split())
print(n,m)

data_map = [0 for _ in range(n)]

for i in range(n):
    data_map[i] = list(map(int,sys.stdin.readline().split()))

pos = deque()
pos.append([0,0])
while True:
    new_pos = deque()
    for i in pos:
        
        1


def in_map(a,b,n,m):
    if(a < n and b < m and a >= 0 and b >= 0)::
        return True
    return False