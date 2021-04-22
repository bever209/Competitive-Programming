a=int(input())

for fewfweefw in range(a):
    lst=input().split()

    lst=[int(k) for k in lst]

    tile=[]
    white=0
    for reufhuf in range(lst[0]):
        p=input()
        
        lst_p=[]
        for k in p:
            if k==".":
                white+=1
            lst_p.append(k)
        tile.append(lst_p)

    p1=lst[2]
    p2=lst[3]

    cost=0
    if p1*2<=p2:
        print (white*p1)
    else:
        check=-345678
        for i in range(len(tile)):
            for j in range(len(tile[i])):
                if j!=len(tile[i])-2 and tile[i][j]=="." and tile[i][j+1] == "." and j!=check:
                    cost=cost+p2
                    check=j+1
                else:
                    if len(tile[i])==1 and tile[i][j]==".": 
                        cost=cost+p1
                    elif len(tile[i])!=1 and tile[i][j]=="." and j!=check:
                        cost=cost+p1
        print (cost) 
    
    
    
