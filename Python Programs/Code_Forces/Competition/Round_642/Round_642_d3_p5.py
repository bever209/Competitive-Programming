a=int(input())

for ufui in range(a):
    lst=input().split()
    lst=[int(i) for i in lst]

    k=lst[1]
    lamp=input()

    ind=[]

    for i in range(len(lamp)):
        if lamp[i]=="1":
            ind.append(i)

    gap=[]
    for i in range(len(ind)):
        if i!=0:
            gap.append(ind[i]-ind[i-1])

    
    

    
    
    
