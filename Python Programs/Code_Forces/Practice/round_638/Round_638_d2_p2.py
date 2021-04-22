a=int(input())

for ijfof in range(a):
    vals=input().split()

    vals=[int(m) for m in vals]
    n=vals[0]
    k=vals[1]
    
    lst=input().split()
    lst=[int(m) for m in lst]
    
    if len(set(lst))>k:
        print ("-1")
    else:
        check=0
        for i in range(len(lst[:(1-k)])):
            for j in lst:
                if j not in lst[i:i+4]:
                    check=1
                    break
            if check==1:
                break
        if check==1:
            print ("-1")
        else:
            rep=len(lst)//k
            rep=rep+1
            flst=lst[:k]*rep

            flst=[str(p) for p in flst]

            print (" ".join(flst))
        
