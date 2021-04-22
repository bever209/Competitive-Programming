a=int(input())

for ifei in range(a):
    vals=input().split()

    vals=[int(i) for i in vals]
    n=vals[0]
    k=vals[1]
    
    if n<k or (n%2==1 and k%2==0):
        print ("NO")
    else:
        if k%2==0:
            count=k-1
            n=n-count
            if n!=0:
                print ("YES")
                print ("1 "*count + str(n))
            
        else:
            if n%2==0:
                if n/2>=k:
                    print ("YES")
                    print ("2 "*(k-1) + str(n-(2*(k-1))))
                else:
                    print ("NO")
            else:
                print ("YES")
                print ("1 "*(k-1) + str(n-(1*(k-1))))
                    
