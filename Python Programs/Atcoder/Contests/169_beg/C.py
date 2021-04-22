a=input().split()

b=int(a[0])
lst=list(a[1])

del lst[-3]

c=""
for i in lst:
    c=c+i
c=int(c)

print (int(b*c//100))
