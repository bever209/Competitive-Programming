a=int(input())

for ijfof in range(a):
    n=int(input())

    pile1=0
    pile2=0

    pile1=pile1+2**n

    count=int(n/2 - 1)

    for i in range(1,count+1):
        pile1=pile1+2**i

    pile2=2**(n+1)-2-pile1

    print (int(abs(pile1-pile2)))
