
vals=input().split()
vals=[int(p) for p in vals]
x=vals[1]

lst=input().split()
lst=[int(p) for p in lst]

days=[]

for v in lst:
    for p in range(v+1):
        if p!=0:
            days.append(p)

days=days+days

maximum=0
for i in range(len(days)):
    if sum(days[i:i+x])>maximum:
        maximum=sum(days[i:i+x])

print (maximum)
