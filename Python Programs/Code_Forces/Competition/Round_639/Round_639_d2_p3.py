numt=int(input())

for feiu in range(numt):
    n=int(input())
    lst=input().split()

    lst=[int(p) for p in lst]
    
    check=0
    
    for val in range(n):
        after=[]
        for i in range(n):
            after.append(i)

        for j in range(len(after)):
            after[j]=after[j]+lst[(j+val)%n]
        
        if sorted(after)!=sorted(list(set(after))):
            check=1
            break

    if check==0:
        print ("YES")
    elif check==1:
        print ("NO")
