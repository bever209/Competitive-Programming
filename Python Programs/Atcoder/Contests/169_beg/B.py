wfwfe=input()
check=0
b=input().split()
if "0" in b:
    print (0)
else:
    
    count=1
    for i in b:
        count=count*int(i)
        
        if count>10**18:
            print (-1)
            check=1
            break
    if check==0:
        print (count)
        
