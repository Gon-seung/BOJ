import sys
import heapq

case = int(sys.stdin.readline())

data = []

for _ in range(case):
    input = int(sys.stdin.readline())
    if input == 0:
        if(len(data) == 0):
            print(0)
        else:
            print(heapq.heappop(data))
    else:
        heapq.heappush(data,input)
    #print(data)