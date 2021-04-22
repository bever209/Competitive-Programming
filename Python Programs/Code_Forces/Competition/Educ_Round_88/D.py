p=int(input())
vals=input().split()
vals=[int(p) for p in vals]

csum=0
bsum=-31
start=0
end=0
bstart=0
bend=0

for i in range(len(vals)):
    if csum<0:
        start=i
        end=i+1
        csum=vals[i]
    else:
        csum=vals[i]+csum
        end = i+1
    if csum>bsum:
        bsum=csum
        bstart=start
        bend = end

if max(vals)>0:
    a=max(vals[bstart:bend])

    print (bsum-a)
else:
    print (0)
