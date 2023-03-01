
import sys
N, M = map(int, sys.stdin.readline().split())

def check_in(x,y,n,m):
    if(x < 0 or y < 0 or x >= n  or y >= m):
        return False
    return True

travel = [[False for _ in range(M)] for _ in range(N)]
data = [[0 for _ in range(M)] for _ in range(N)]

for i in range(N):
    input = sys.stdin.readline()
    for j in range(M):
        data[i][j] = input[j]

move = [[1,0,0]]
pos = 0
times = 1
travel[0][0] = True
while travel[N-1][M-1] == False:
    while(pos < len(move) and move[pos][0] == times):
        _,x,y = move[pos]
        if(check_in(x + 1,y,N,M) and travel[x + 1][y] == False and data[x+1][y] == '1'):
            move.append([times + 1 , x + 1 , y])
            travel[x + 1][y] = True
        if(check_in(x,y + 1,N,M) and travel[x][y + 1] == False and data[x][y + 1] == '1'):
            move.append([times + 1 , x, y + 1])
            travel[x][y + 1] = True
        if(check_in(x - 1,y,N,M) and travel[x - 1][y] == False and data[x-1][y] == '1'):
            move.append([times + 1 , x - 1 , y])
            travel[x - 1][y] = True
        if(check_in(x,y - 1,N,M) and travel[x][y - 1] == False and data[x][y - 1] == '1'):
            move.append([times + 1 , x , y - 1])
            travel[x][y - 1] = True
        pos += 1
    times += 1
print(times)
