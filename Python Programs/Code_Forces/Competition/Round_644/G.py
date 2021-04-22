a=int(input())

for fewfweefw in range(a):
    lst=input().split()
    lst=[int(p) for p in lst]

    n=lst[0]
    m=lst[1]
    a=lst[2]
    b=lst[3]

    if n*a==m*b:
        print ("YES")
        
    else:
        print ("NO")
    
