
import sys

M, N, H = map(int,sys.stdin.readline().split())

data = [[[0 for _ in range(M)] for _ in range(N)] for _ in range(H)]

def check_in(x,y,z):
    if(x < 0 or y < 0 or z < 0 or x >= N or y >= M or z >= H):
        return False
    return True

total_num = N * M * H
time = 0
possible = True
cur_num = 0
pos = []
for k in range(H):
    for j in range(N):
        input = list(map(int,sys.stdin.readline().split()))
        for i in range(M):
            data[k][j][i] = input[i]
            if(input[i] == -1):
                total_num -=1
            if(input[i] == 1):
                cur_num +=1
                pos.append([0,j,i,k])

i_in_pos = 0
while(cur_num != total_num):
    prev_num = cur_num
    while(i_in_pos < len(pos) and pos[i_in_pos][0] == time):
        _,x, y, z = pos[i_in_pos]
        if(check_in(x + 1,y,z) and data[z][x + 1][y] == 0):
            data[z][x + 1][y] = 1
            pos.append([time + 1 , x + 1, y, z])
            cur_num += 1
        if(check_in(x - 1,y,z) and data[z][x - 1][y] == 0):
            data[z][x - 1][y] = 1
            pos.append([time + 1 , x - 1, y, z])
            cur_num += 1
        if(check_in(x,y + 1,z) and data[z][x][y + 1] == 0):
            data[z][x][y + 1] = 1
            pos.append([time + 1 , x, y + 1, z])
            cur_num += 1
        if(check_in(x,y - 1,z) and data[z][x][y - 1] == 0):
            data[z][x][y - 1] = 1
            pos.append([time + 1 , x, y - 1, z])
            cur_num += 1
        if(check_in(x,y,z + 1) and data[z + 1][x][y] == 0):
            data[z + 1][x][y] = 1
            pos.append([time + 1 , x, y, z + 1])
            cur_num += 1
        if(check_in(x,y,z - 1) and data[z - 1][x][y] == 0):
            data[z - 1][x][y] = 1
            pos.append([time + 1 , x, y, z - 1])
            cur_num += 1
        i_in_pos += 1
    time += 1
    #print(pos)
    if(prev_num == cur_num):
        time = -1
        break
print(time)
