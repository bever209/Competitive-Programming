a=int(input())

for fewfweefw in range(a):
    
    lst=input().split()
    lst=[int(p) for p in lst]


    if lst[0]%2==0:
        print (int((lst[0]/2)*lst[1]))
    elif lst[1]%2==0:
        print (int((lst[1]/2)*lst[0]))
    else:
        a=lst[0]*(lst[1]//2)

        a=a+lst[0]//2+1

        print (int(a))
