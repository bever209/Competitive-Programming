a=int(input())

def candy(lst,prev,reverse):
    total=0
    if reverse:
        for i in range(len(lst)):
            
            i=len(lst)-i-1
            total+=lst[i]
            if total>prev or i==0:
                del lst[i:]

                return total,lst
    else:
        for i in range(len(lst)):
            total+=lst[i]
            if total>prev or i==len(lst)-1:
                del lst[:i+1]

                return total,lst

for ifei in range(a):
    num=int(input())

    lst=input().split()

    lst=[int(i) for i in lst]

    a=0
    b=0
    count=-1
    prev=0
    while len(lst)>0:
        count+=1
        if count%2==0:
            lst2=candy(lst,prev,False)

            a=a+lst2[0]
            prev=lst2[0]
            lst=lst2[1]
        else:
            lst2=candy(lst,prev,True)

            b=b+lst2[0]
            prev=lst2[0]
            lst=lst2[1]

    print (count+1,a,b)

    
    
