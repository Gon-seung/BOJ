
import sys
from collections import deque

'b' - 'a'

size = int(sys.stdin.readline())
tree = [[] for _ in range(size)]

for i in range(size):
    input = list(sys.stdin.readline().split())
    tree[i] = input

save = deque('A')
trip = [False for _ in range(size)]
trip[0] = True
print(save)
output = ['A']
while(len(save) != 0):
    node = save[-1]
    left = tree[node - 'A'][1]
    right = tree[node - 'A'][2]
    if(left == '.'):
        if(right == '.'):
            save.pop()
    elif(not trip[left - 'A']):
        trip[left] = True
        output.append(left)
        save.append(left)
    elif(right == '.' or trip[right - 'A']):
        save.pop()
    else:
        save.append(right)
        output.append(right)
        trip[right] = True


