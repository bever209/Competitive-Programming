effe=int(input())

lst=input().split()

for i in range(len(lst)):
    if lst[i]=="B":
        if i==0:
            if lst[i+1]=="D":
                lst[i]="U"
            else:
                lst[i]="D"
        elif i==len(lst)-1:
            if lst[-1]=="U":
                lst[i]="D"
            else:
                lst[i]="U"
        else:
            if lst[i+1]=="U" and lst[i-1]=="U":
                lst[i]="D"
            elif lst[i+1]=="D" and lst[i-1]=="D":
                lst[i]="U"
            else:
                lst[i]="U"

print (" ".join(lst))
        
