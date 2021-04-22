a=int(input())

for fewwf in range(a):
    lst=input().split()
    lst=[int(i) for i in lst]

    if lst[0]==1:
        print ('0')
    elif lst[0]==2:
        print (lst[1])
    else:
        print (2*lst[1])
