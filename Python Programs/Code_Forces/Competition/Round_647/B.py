
a=int(input())

for fewfweefw in range(a):
    num=input()
    ind=[]
    for i in range(len(num)):
        if num[i]==1:
            ind.append(i)
            
    if len(num)<3 or "1" not in num or sorted(ind) == list(range(min(ind), max(ind)+1)):
        print (0)
    else:
        a=len(ind)

        gaps=[]
        for p in range(len(ind)):
            if p!=0:
                gaps.append(ind[p+1]-ind[p]-1)
            else:
                gaps.append(ind[p])

        count=0

        for j in gaps:
            
            

    
