
count=1

a=int(input())

p=int(a**(1/2))

answer=0

while a!=1:
    count+=1
    if count<p:
        if a%count==0:
            time=1
            while a%(count**time)==0:
                time+=1
            time=time-1
            a=a/(count**time)
            time=time*2
            time=int(time**(1/2))
            answer=answer+time
            
    else:
        break
if a>1:
    answer+=1
print (answer)
