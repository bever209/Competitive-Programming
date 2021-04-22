file=open("4int_testdata.txt","r")
file=file.readlines()

for i in range(len(file)):
    file[i]=file[i].strip()
    file[i]=file[i].split()
    for j in range(len(file[i])):
        file[i][j]=int(file[i][j])

################################################################################################
def prime(num):
    t=0
    for val in range(2,num):
        if num%val==0:
            t=1
            return False
    if t==0:
        return True

###################################################################################################
def rule_7(p1):
    check=0
    #print ("b")
    for num in both_order:
        if num<= (new_pos+6) and num>(new_pos):
            check=1
            return num-1
            break
    if check==0:
        return new_pos+6

def rule_8(p1):
    #print ("c")
    check=0
    for num in both_order[::-1]:
        if num>= (new_pos-6) and num<(new_pos):
            check=1
            #print (num)
            return num+1
            
    if check==0:
        return new_pos-6

#####################################################################################################
def move(roll,p1,p2):
    rule7_8_check=0
    global val
    val=p1[0]
    
    global new_pos
    new_pos=val+roll
    
    global both_order
    both_order=sorted(p1+p2)
    
    #print (new_pos,p1)
    count=0
    rule_9=[[6,8],[11,13],[16,18],[21,23],[26,28],[34,36],[39,41],[44,46],[49,51]]
    
    if p1[0]==52 and p1[1]==52 and p1[2]==52:
        p1=["Game Over"]
        return p1
    if (new_pos in p1 or new_pos in p2 or new_pos>52) and new_pos!=52:
        #print ("a")
        count=1
        p1[0]=val
        new_pos=val
        return p1

    if new_pos**(1/2) != int(new_pos**(1/2)) and (not prime(new_pos)):
        multiple=False
        for i in rule_9:
            if i[0]>=val and i[1]<=new_pos:
                multiple=True
                break
        if multiple:
            rule7_8_check=1
            #print ("d")
            count=1
            for j in range(new_pos+1,val,-1):
                if j%roll==0 and j not in p1 and j not in p2:
                    p1[0]=j
                    break
            return p1
    
    if prime(new_pos) and rule7_8_check==0:
        #print ("b")
        count=1
        p1[0]=rule_7(p1)
        

    if new_pos**(1/2) == int(new_pos**(1/2)) and new_pos>4 and rule7_8_check==0:
        #print ("c")
        count=1
        p1[0]=rule_8(p1)
        
        
    
    
    if count==0:
        #print ("e")
        p1[0]=new_pos
    #print (p1,roll)
    
    return p1
    
                    
                    
        


####################################################################################################
fileo=open("vangara_4int_patolli.txt","w")
for lst in file:
    
    p1_place=sorted(lst[:3])
    del lst[:3]
    p2_place=sorted(lst[:3])
    del lst[:3]

    roll=lst
   
    del roll[0]

    
    for j in roll:
        if len(p2_place)!=0:
            p2_place=sorted(move(j,p2_place,p1_place))
            for v in range(len(p2_place)):
                if p2_place[v]==52:
                    del p2_place[v]
            #print (p2_place,"main")
        else:
            p2_place=["Game Over "]
   
    if len(p2_place)!=0:
        p2_place=[str(p) for p in p2_place]
        fileo.write(" ".join(p2_place)+"\n")
    else:
        fileo.write("Game Over "+"\n")

fileo.close()
    
