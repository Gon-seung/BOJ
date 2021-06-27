from collections import deque
import sys

num = int(sys.stdin.readline())

left = deque()
right = deque(range(1, num + 1))
right.reverse()
answer = []
cantmake = True
for i in range(num):
    input = int(sys.stdin.readline())
    if(not cantmake):
        continue
    while(len(left) == 0 or left[-1] != input):
        if(len(right) > 0):
            move = right.pop()
            left.append(move)
            answer.append("+")
        else:
            cantmake = False
            break
    if(not cantmake):
        continue

    answer.append("-")
    left.pop()

if(cantmake):
    for i in answer:
        print(i)
else:
    print("NO")