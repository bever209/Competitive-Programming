a=int(input())

for ufui in range(a):
    val=int(input())

    lst=[0]*val

    for term in range(val):
        max_l=0
        ind=[0,0]
        
        for i in range(len(lst)):
            
            for j in range(len(lst)+1):
                if len(set(lst[i:j]))==1 and j-i>ind[1]-ind[0] and lst[i:j][0]==0 and i<j:
                    ind[0]=i
                    ind[1]=j
        lst[(ind[0]+ind[1]-1)//2]=term+1

    lst=[str(p) for p in lst]

    print (" ".join(lst))
