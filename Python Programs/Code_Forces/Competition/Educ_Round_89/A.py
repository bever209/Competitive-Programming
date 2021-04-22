a=int(input())

for uifehfwi in range(a):
    
    lst=input().split()
    lst=[int(p) for p in lst]
    a=lst[0]
    b=lst[1]

    if (a<b and a*2<b) or (b<a and b*2<a):
        print (int(min(a,b)))
    else:
        count=int(min(2*(a//3),2*(b//3)))
        a=a-3*(a//3)
        b=b-3*(b//3)

        if (a>=2 and b>=1) or (a>=1 and b>=2):
            count+=1

        print (count)
