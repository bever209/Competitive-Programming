a=int(input())

for fewfweefw in range(a):
    
    lst=input().split()
    lst=[int(p) for p in lst]

    n=lst[0]
    m=lst[1]
    k=lst[2]

    card=n/k

    if card>=m:
        print (int(m))
    else:
        m=m-card

        k=k-1

        if m%k==0:
            print (int(card-m//k))
        else:
            a=m//k

            print (int(card-a-1))

        
