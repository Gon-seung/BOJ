import sys
import heapq

case = int(sys.stdin.readline())

left = []
right = []
for _ in range(case):
    input = int(sys.stdin.readline())
    if(len(right) >= len(left)):
        heapq.heappush(left,[-input, input])
    else:
        heapq.heappush(right,[input , input ] )
    while(len(left) > 0 and len(right) > 0 and right[0][1] < left[0][1]):
        min = heapq.heappop(right)[1]   
        max = heapq.heappop(left)[1]   
        heapq.heappush(left,[-min, min])
        heapq.heappush(right,[max , max] )
    
    
    print(left[0][1])
