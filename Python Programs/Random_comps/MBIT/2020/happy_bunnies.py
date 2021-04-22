lst=input().split()
lst=[int(p) for p in lst]

r=range(lst[0],lst[1]+1)

count=0
for i in r:
    if "7" not in str(i):
        count=count+i
        count2=0
        for j in str(i):
            count2=count2+int(j)

        count=count+count2
print (count)
