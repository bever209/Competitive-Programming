a=input().split()
a=[int(p) for p in a]

lst=input().split()
lst=[int(k) for k in lst]

for fihwfwhfwehiu in range(a[1]):
    t=input().split()
    t=[int(n) for n in t]
    t=sorted(t)

    print (min(sum(lst[t[0]-1:t[1]-1]),sum(lst)-sum(lst[t[0]-1:t[1]-1])))
