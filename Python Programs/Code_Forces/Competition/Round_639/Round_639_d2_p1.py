numt=int(input())

for fuioi in range(numt):
    lst=input().split()
    lst=[int(k) for k in lst]

    n_con=(lst[0]-1)*(lst[1]) + (lst[1]-1)*(lst[0])

    n_p=lst[0]*lst[1]

    if n_p>=n_con:
        print ("YES")
    else:
        print ("NO")
