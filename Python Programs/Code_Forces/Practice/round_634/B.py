a=int(input())

for ufwi in range(a):
    string="abcdefghijklmnopqrstuvwxyz"

    lst=input().split()
    lst=[int(p) for p in lst]

    length=lst[0]
    n=lst[2]

    o=""

    for i in range(length):
        o=o+string[i%n]
    print (o)
