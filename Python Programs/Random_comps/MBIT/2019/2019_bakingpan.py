a=int(input())

lst=[]
for fufu in range(a):
    t=input().split()
    t=[int(p) for p in t]
    lst.append(t)

x_vals=[]
y_vals=[]
for i in lst:
    x_vals.append(i[0]+i[2])
    x_vals.append(i[0]-i[2])

    y_vals.append(i[1]+i[2])
    y_vals.append(i[1]-i[2])

print ((max(x_vals)-min(x_vals))*(max(y_vals)-min(y_vals)))

    
