a=int(input())

for fewfweefw in range(a):
    
    lst=input().split()
    lst=[int(p) for p in lst]

    n=lst[0]
    k=lst[1]

    for i in range(1,n)[::-1]:
       if n/i == int(n/i) and n/i<=k:
           break
    if k>=n:
        i=n
    print (int(n/i))
