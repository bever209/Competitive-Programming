a=int(input())

for fewfweefw in range(a):
    integer=int(input())
    lst=input().split()

    lst=[int(p) for p in lst]

    lst=sorted(lst)

    count=843513865668464568495138465143865134386513
    for val in range(len(lst)):
        if val!=0:
            if abs(lst[val]-lst[val-1])<count:
                count=abs(lst[val]-lst[val-1])

    print (count)
    
