a=int(input())

for fewfweefw in range(a):
    integer=int(input())
    lst=input().split()

    lst=[int(p) for p in lst]
    lst=sorted(lst)
    num_p=1
    
    for i in range(len(lst)):
        if num_p-1<=i:
            if lst[i]<=num_p:
                num_p=num_p+1
            else:
                for j in range(1,len(lst)+1):
                    if j>i+1:
                        if max(lst[i:j])<num_p+j-i:
                            num_p=num_p+j-i
                            break
    print (num_p)

    
