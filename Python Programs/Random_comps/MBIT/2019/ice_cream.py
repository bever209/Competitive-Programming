file=open("ice.txt","r")
file=file.readlines()

for i in range(len(file)):
    file[i]=file[i].strip()

a=int(file[0])
del file[0]

