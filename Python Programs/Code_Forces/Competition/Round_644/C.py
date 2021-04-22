a=int(input())

for fewfweefw in range(a):
    a=int(input())

    lst=input().split()

    lst=[int(p) for p in lst]

    odd=[]
    even=[]

    for i in lst:
        if i%2==0:
            even.append(i)
        else:
            odd.append(i)

    if len(odd)%2==0 and len(even)%2==0:
        print ("yes")
    else:
        if len(odd)%2==1 and len(even)%2==1:
            check=True
            for val in odd:
                if val+1 in even or val-1 in even:
                    check=False
                    print ("yes")
                    break
            if check:
                print ("no")
        elif len(odd)%2==1 and len(even)%2==0:
            check=True
            for val in odd:
                if val+1 in even or val-1 in even:
                    check=False
                    print ("yes")
                    break
            if check:
                print ("no")
        elif len(even)%2==1 and len(odd)%2==0:
            check=True
            for val in even:
                if val+1 in odd or val-1 in odd:
                    print ("yes")
                    check=False
                    break
            if check:
                print ("no")

    
