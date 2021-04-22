a=int(input())

for fewfweefw in range(a):
    
    lst=input().split()
    nums=input().split()
    nums=[int(p) for p in nums]

    n=int(lst[0])
    x=int(lst[1])

    even=0
    odd=0
    for i in nums:
        if i%2==0:
            even+=1
        else:
            odd+=1

    if odd>0:
        if (n==x and odd%2==1) or x<n:
            if odd==n and x%2==0:
                print ("no")
            else:
                print ("yes")
        else:
            print ("no")
    else:
        print ("no")
            
                
            
