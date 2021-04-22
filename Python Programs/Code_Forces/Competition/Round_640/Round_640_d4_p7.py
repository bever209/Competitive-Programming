a=int(input())

for ifei in range(a):
    val=int(input())

    if val==2 or val==3:
        print ("-1")
    else:
        
        lst=[3,1,4,2]

        for i in range(val-4):
            i=i+5

            if i%2==1:
                lst.append(i)
            else:
                v1=i-2
                v2=i-4

                ind1=lst.index(v1)
                ind2=lst.index(v2)

                ind=max(ind1,ind2)
                lst.insert(ind,i)
        lst=[str(j) for j in lst]
        print (" ".join(lst))
    
