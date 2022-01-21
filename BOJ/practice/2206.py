
import sys

N, M = map(int,sys.stdin.readline().split())

data = [[0 for _ in range(M)] for _ in range(N)]
travel = [[[False for _ in range(M)] for _ in range(N)] for _ in range(2)]
for i in range(N):
    input = sys.stdin.readline()
    for j in range(M):
        data[i][j] = int(input[j])

def check_in(x,y):
    if(x < 0 or y < 0 or x >= N or y >= M):
        return False
    return True

move = [[1,0,0,0]]
# move = dis, break_wall, x, y
pos = 0
dis = 1
neightbor = [[1,0],[-1,0],[0,1],[0,-1]]
travel[0][0][0] = True
while not (travel[0][N-1][M-1] or travel[1][N-1][M-1]):
    pre_len = len(move)
    while(pos < len(move) and move[pos][0] == dis):
        _,breakwall,x,y = move[pos]
        for x_plus, y_plus in neightbor:
            new_x = x+x_plus
            new_y = y+y_plus
            if(check_in(new_x,new_y)):
                if(data[new_x][new_y] == 0 and travel[breakwall][new_x][new_y] == False):
                    travel[breakwall][new_x][new_y] = True
                    move.append([dis+1, breakwall,new_x,new_y])
                elif(data[new_x][new_y] == 1 and breakwall == 0 and travel[1][new_x][new_y] == False):
                    travel[1][new_x][new_y] = True
                    move.append([dis+1, 1,new_x,new_y])
        pos += 1
    if(pre_len == len(move)):
        dis = -1
        break
    dis += 1
print(dis)
