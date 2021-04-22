def swap(i,j,a,b):
    temp=a[i]
    temp2=b[j]

    b[j]=temp
    a[i]=temp2

    return a,b

a=int(input())

for ufui in range(a):
    lst=input().split()
    lst=[int(i) for i in lst]

    
    a=input().split()
    a=[int(i) for i in a]
    
    b=input().split()
    b=[int(i) for i in b]

    for p in range(lst[1]):
        val=min(a)
        ind1=a.index(val)

        val2=max(b)
        ind2=b.index(val2)
        if val<val2:
            final=swap(ind1,ind2,a,b)
            a=final[0]
            b=final[1]
    print (sum(a))

        
    
    


