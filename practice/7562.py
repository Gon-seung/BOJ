import sys

case = int(sys.stdin.readline())

move = [[2,1],[1,2],[-1,-2],[-2,-1],[2,-1],[1,-2],[-2,1],[-1,2]]

def check_in(x,y,size):
    if x < 0 or y < 0 or x >= size or y >= size:
        return False
    return True

for _ in range(case):
    size = int(sys.stdin.readline())

    data = [[False for _ in range(size)] for _ in range(size)]
    x,y = map(int,sys.stdin.readline().split())
    final_x,final_y = map(int,sys.stdin.readline().split())
    data[x][y] = True
    time = 0
    move_his = [[time,x,y]]
    pos = 0
    while(data[final_x][final_y] == False):
        while(move_his[pos][0] == time):
            _,x,y = move_his[pos]
            for x_plus,y_plus in move:
                new_x = x + x_plus
                new_y = y + y_plus
                if(check_in(new_x,new_y,size) and data[new_x][new_y] == False):
                    data[new_x][new_y] = True
                    move_his.append([time+1,new_x,new_y])
            pos += 1
        time += 1
    print(time)
                
    
