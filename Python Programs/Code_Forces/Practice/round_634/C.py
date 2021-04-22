a=int(input())

for uiger in range(a):
    l=int(input())
    lst=input().split()
    lst=[int(p) for p in lst]

    most=0
    amount=0

    for p in lst:
        if lst.count(p)>amount:
            most=p
            amount=lst.count(p)

    other=[]
    for p in lst:
        if p!=most:
            other.append(p)

    other=(set(other))

    if amount<=len(other):
        print (amount)
    else:
        if amount-len(other)==1:
            print (len(other))
        else:
            print (len(other)+1)
