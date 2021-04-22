file=open("candle.txt","r")

file=file.readlines()
for val in range(len(file)):
    file[val]=file[val].strip()
    file[val]=file[val].split()
    
    

a=file[0]
del file[0]
a=[int(p) for p in a]

lst=[]
for i in range(a[0]):
    file[0]=[int(q) for q in file[0]]

    lst.append(file[0])

    del file[0]



n=int(file[0][0])
del file[0]

change=[]

for i in file:
    i=[int(q) for q in i]

    change.append(i)

for i in change:
    for j in range(len(lst)):
        
        for k in range(len(lst[j])):
            

            if i[0]<=j+1 and j+1<=i[2] and i[1]<=k+1 and k+1<=i[3]:
                
                lst[j][k]=1-lst[j][k]
    

count=0
for i in lst:
    for j in i:
        if j==1:
            count+=1

print (count)
