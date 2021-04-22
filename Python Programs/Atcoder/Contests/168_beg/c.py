import math
lst=input().split()
lst=[int(p) for p in lst]

a=lst[0]
b=lst[1]
h=lst[2]
m=lst[3]

deg1=(60*h+m)/720
deg2=m/60

diff=abs(deg1-deg2)*360
if diff>180:
    diff=diff-180

v=math.cos(diff*math.pi/180)

sq=a**2+b**2-2*a*b*v

c=sq**(1/2)

print (c)
