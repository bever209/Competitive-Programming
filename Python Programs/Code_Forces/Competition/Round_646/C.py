import math
a=int(input())

    
for fewfweefw in range(a):

    lst=input().split()

    lst=[int(p) for p in lst]

    a= abs(lst[0]-lst[2])
    b=abs(lst[1]-lst[3])
    if a==0 or b==0:
        print (1)
    else:
        
        print (int(math.factorial(a+b)/(math.factorial(a)*math.factorial(b))))

    

    
