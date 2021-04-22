def power_2(c):
    while c!=1:
        if c!=int(c):
            return False
        else:
            c=c/2
    return True
def number(c):
    count=0
    while c!=1:
        count+=1
        c=c/2
    return count
        
a=int(input())

for fewfweefw in range(a):
    
    lst=input().split()
    lst=[int(p) for p in lst]

    a=lst[0]
    b=lst[1]

    if a==b:
        print (0)
    else:
        c=a/b
        d=b/a

        if power_2(c):
            a = number(c)

            s=a//3 + (a-a//3)//2
            a=a-((a-a//3)//2)
            s=s+a

            print (int(s))
        elif power_2(d):
            a = number(d)

            s=a//3 + (a-a//3)//2
            a=a-((a-a//3)//2)
            s=s+a

            print (int(s))
        else:
            print (-1)

        
                
            
