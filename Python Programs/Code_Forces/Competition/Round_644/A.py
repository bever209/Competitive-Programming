a=int(input())

for fewfweefw in range(a):
    
    lst=input().split()
    lst=[int(p) for p in lst]
    lst=sorted(lst)[::-1]
    a=lst[0]
    b=lst[1]

    if a>2*b:
        print (a**2)
    else:
        print ((2*b)**2)
