import heapq
import sys

n = int(sys.stdin.readline())
list = []

for _ in range(n):
    x = int(sys.stdin.readline())
    if x == 0:
        if len(list) != 0:
            print(heapq.heappop(list)[1])
        else:
            print(0)
    else:
        heapq.heappush(list, [-x, x])
    #print(list)