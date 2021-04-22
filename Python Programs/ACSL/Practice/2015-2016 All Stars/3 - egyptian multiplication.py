file=open("3.txt","r")
file=file.readlines()

for i in range(len(file)):
    file[i]=file[i].split(",")

for i in range(len(file)):
    for j in range(len(file[i])):
        file[i][j]=int(file[i][j])

for lst in file:
    num=lst[0]

    num=str(bin(num))
    num=num[0]+num[2:]

    sums=[]
    for i in range(1,len(num)+1):
        if num[len(num)-i]=="1":
            sums.append(2**(i-1) *int(lst[1]))

    sums=sorted(sums)[::-1]
    sums=[str(p) for p in sums]
    print (",".join(sums))

