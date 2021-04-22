a=int(input())

for fewfweefw in range(a):
    lst=input().split()
    lst=[int(p) for p in lst]

    n=lst[0]
    m=lst[1]

    no_count=[]
    for fewf in range(n):
        val=input()
        val=int(val,2)
        no_count.append(val)


    last=2**(m)

    number=last-len(no_count)


    median=last/2 -1
    for i in no_count:
        print (median,i)
        if i<=median:
            median=median+1
        else:
            median=median-1
    a=bin(int(median))
    if len(a[2:])<m:
                diff=m-len(a[2:])
                a="0"*diff + a[2:]
                print (a)
    else:
        a=a[2:]
        print (a)
