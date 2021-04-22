a=int(input())
for ifei in range(a):
    n=int(input())
    lst=input().split()

    lst=[int(p) for p in lst]

    
    count=0
    checker=[]
    for i in lst:
        checker.append(i)
    
    for i in range(len(lst)-count):
        for j in range(len(lst)-count):
            if i!=j and i<j:
                if sum(lst[i:j]) in checker:
                    index=checker.index(sum(lst[i:j]))
                    del checker[index]
                    
                    count+=1
                    
            





                        
    print (count)
                    
    

    
    
    
