a=int(input())

for ifei in range(a):
    val=(input())
    val=list(val)
    count=0
    
    for i in val:
        if i!="0":
            count+=1
    print (count)

    lst=[]
    num=-1
    for j in val[::-1]:
        num+=1
        if j!="0":
            lst.append(j + "0"*num)
    print (" ".join(lst))
    
