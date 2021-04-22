numt=int(input())

def num_p(card):
    check=0
    count=1
    while True:
        if ((3*count*count+count)/2)>card:
            card=card-((3*(count-1)*(count-1)+count-1)/2)
            break
        
        check=1
        count=count+1
    return check,card

for uigrf in range(numt):
    card=int(input())
    count=0
    while True:
        lst=num_p(card)
        card=lst[1]

        if lst[0]==0:
            break
        else:
            count+=1
    print (count)

