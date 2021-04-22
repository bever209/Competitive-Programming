file=open("sugar.txt","r")
file=file.readlines()

a=int(file[0])
del file[0]

for i in range(len(file)):
    file[i]=file[i].strip()

    file[i]=file[i].split()

    file[i]=[int(p) for p in file[i]]

