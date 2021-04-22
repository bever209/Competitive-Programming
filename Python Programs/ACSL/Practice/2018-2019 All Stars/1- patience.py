file=open("1.txt","r")
file=file.readlines()

for i in range(len(file)):
    file[i]=file[i].strip()
    file[i]=file[i].split()

order=["A","2","3","4","5","6","7","8","9","T","J","Q","K"]


for i in file:
    
    lst=[]
    pile=[]
    
    for j in i:
        if j==i[0]:
            pile.append(j)
            
        else:
            #print (j,lst,pile)
            if len(lst)>0:
                check=0
                
                for term in range(len(lst)):
                    val=lst[term]
                    a=order.index(val[-1][0])
                    b=order.index(j[0])
                    if a>b or (val[-1][0]=="K" and j[0]=="A") or (val[-1][0]=="A" and j[0]=="K"):
                        if j[1]!=val[-1][1]:
                            lst[term].append(j)
                            #print (j,"a")
                            check=1
                            break
                      
                        
                if check==0:
                    check2=0
                    a=order.index(pile[-1][0])
                    b=order.index(j[0])
                    
                    if a>b or (pile[-1][0]=="K" and j[0]=="A") or (pile[-1][0]=="A" and j[0]=="K"):
                        if j[1]!=pile[-1][1]:
                            pile.append(j)
                            #print (j,"c")
                            check2=1
              
                            
                    if check2==0:
                        lst.append(pile)
                        pile=[]
                        pile.append(j)
                        #print (j,"e")
                        
            else:
                a=order.index(pile[-1][0])
                b=order.index(j[0])
                check3=0
                if a>b or (pile[-1][0]=="K" and j[0]=="A") or (pile[-1][0]=="A" and j[0]=="K"):
                
                    if j[1]!=pile[-1][1]:
                        check3=1
                        pile.append(j)
                  

                    if check3==0:
                        lst.append(pile)
                        pile=[]
                        pile.append(j)
                else:
                    lst.append(pile)
                    pile=[]
                    pile.append(j)
                    
    if len(pile)>0:       
        lst.append(pile)

    count=0
    for p in lst:
        if len(p)>count:
            count=len(p)
    f=[]
    for q in lst:
        if len(q)==count:
            f.append(q)
    lst2=[]
    for m in f:
        count2=0
        for t in m:
            count2=count2+order.index(t[0])+1
        lst2.append(count2)
    
    print (min(lst2))
                        
            
