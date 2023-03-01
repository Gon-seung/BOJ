
a = [1,2,7,4,5]

for i in a[::-1]:
    print(i)
    a.pop()
    print(a)
    print('- : ' ,i)