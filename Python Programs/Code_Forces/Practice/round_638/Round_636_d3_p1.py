numt=int(input())

for fr in range(numt):
    total=int(input())

    count=0

    sum_x=1
    while True:
        count+=1
        sum_x=sum_x + 2**count
        if total/sum_x==total//sum_x:
            print (int(total/sum_x))
            break
