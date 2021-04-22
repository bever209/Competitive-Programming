file=open("2jr_testdata.txt","r")
lst=file.readlines()
file.close()

for i in range(len(lst)):
    lst[i]=lst[i].strip()
    lst[i]=lst[i].split()

for val in range(len(lst)):
    for j in range(len(lst[val])):
        lst[val][j]=list(lst[val][j])

save=[]

for val in range(len(lst)):
    for val2 in range(len(lst[val])):
        count=0
        for k in range(len(lst[val][val2])):
          
            if k-count!=0 and lst[val][val2][k-count]==lst[val][val2][k-1-count]:
                a=lst[val][val2][k-count-1]
                if a.lower()!="a" or a.lower()!="e" or a.lower()!="i" or a.lower()!="o" or a.lower()!="u":
                    del lst[val][val2][k-count]
                    count+=1

        count=0
        for t in range(len(lst[val][val2])):
            a=lst[val][val2][t-count]
            if t-count!=0 and (a.lower()=="a" or a.lower()=="e" or a.lower()=="i" or a.lower()=="o" or a.lower()=="u"):
                del lst[val][val2][t-count]
                count+=1

    mini_lst=min(len(lst[val][0]),len(lst[val][1]))

    count=0
    for num in range(mini_lst):

        if lst[val][0][num-count]==lst[val][1][num-count]:
            del lst[val][0][num-count]
            del lst[val][1][num-count]
            count+=1
            
    for term in range(len(lst[val])):
        lst[val][term]=lst[val][term][::-1]
        
    mini_lst=min(len(lst[val][0]),len(lst[val][1]))

    count=0
    for num in range(mini_lst):

        if lst[val][0][num-count]==lst[val][1][num-count]:
            del lst[val][0][num-count]
            del lst[val][1][num-count]
            count+=1

    for term in range(len(lst[val])):
        lst[val][term]=lst[val][term][::-1]
    
    if len(lst[val][0])>len(lst[val][1]):
        save.append(lst[val][1])
    elif len(lst[val][0])<len(lst[val][1]):
        save.append(lst[val][0])
    else:
        fin_lst=[]
        fin_lst.append(lst[val][0])
        fin_lst.append(lst[val][1])
        fin_lst2=sorted(fin_lst)
        save.append(fin_lst2[0])
output=open("output_jr2.txt","w")
output.close()

output=open("output_jr2.txt","a")
for i in save:
    t="".join(i)
    output.write(t + "\n")


output.close()
    
    

    
