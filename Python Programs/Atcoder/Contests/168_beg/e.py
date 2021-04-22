a=int(input())
lst=[]

for _ in range(a):
    b=input().split()
    b=[int(p) for p in b]

    lst.append(b)

count=0
count=count+len(lst)
count2=0
for i in range(len(lst)):
    for j in range(len(lst)):
        if i!=j:
            if (lst[i][0]*lst[j][0]+lst[i][1]*lst[j][1])!=0:
                count2=count2+1
count2=count2/2
count=count+count2

print (int(count%1000000007))
