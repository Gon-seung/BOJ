import math
import numpy as np
x= 0.05
x = x*0.15 + 0.35
x = 1/(1+ math.exp(-x))

x = x * 0.4 + 0.6
x = 1/(1+ math.exp(-x))
print(x)
print()
x  =[3.1,3.7,1.8]
print(0.6*x[0]+0.4*x[1]-0.2*x[2] -0.9)
print(-0.3*x[0] + 0.8 * x[1] +0.1 * x[2] -0.1)
print(-0.7*x[0] + 0.4 * x[2] +1.2)

print('-----------------')

h = np.array([0,0])
input = [2,0,1,5,0,5,0,2]
wxh = np.array([0.001,0.003])
whh = np.array([[-1,2],[2,-1]])
why = np.array([[1,0],[0,-1]])
for i in range(8):
    new_x = wxh * input[i]
    h = np.dot(whh, h) + np.dot(wxh,  new_x)
print(np.dot(why,h))