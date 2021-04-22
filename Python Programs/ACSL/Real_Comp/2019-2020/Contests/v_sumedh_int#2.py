file1=open("2int_testdata.txt","r")
lst=file1.readlines()

file1.close()

for i in range(len(lst)):
    lst[i]=lst[i].strip()
    lst[i]=lst[i].split()

for i in range(len(lst)):
    for j in range(len(lst[i])):
        lst[i][j]=(list(lst[i][j].upper()))

final_lst=[]
for i in range(len(lst)):
    a=1
    
    while True:
      if a==0:
        break
      count1=0
      count2=0
      check=0
      a=1
      mini_lst=min(len(lst[i][0]),len(lst[i][1]))
      if mini_lst==0:
          max_lst=max(len(lst[i][0]),len(lst[i][1]))
          final_lst.append(max_lst)
          a=0
          
      for k in range(mini_lst):
          change=0
          for t in range(mini_lst):
              if t-count1>=0 and t-count2>=0 and lst[i][0][t-count1]==lst[i][1][t-count2]:
                  del lst[i][0][t-count1]
                  del lst[i][1][t-count2]
                  count1+=1
                  count2+=1
                  change+=1
                  break

        

          if k-count1>=0 and k-count2-1>=0 and lst[i][0][k-count1]==lst[i][1][k-count2-1]:
            del lst[i][0][k-count1-1]
            count1+=1
            break
        
          elif k-count1-1>=0 and k-count2>=0 and lst[i][0][k-count1-1]==lst[i][1][k-count2]:
            del lst[i][1][k-count2-1]
            count2+=1
            break
          elif k-count2+1<len(lst[i][1]) and k-count1>=0 and k-count2+1>=0 and lst[i][0][k-count1]==lst[i][1][k-count2+1]:
            del lst[i][1][k-count2]
            count1+=1
            break
        
          elif k-count1+1<len(lst[i][0]) and k-count1+1>=0 and k-count2>=0 and lst[i][0][k-count1+1]==lst[i][1][k-count2]:
            del lst[i][0][k-count1]
            count2+=1
            break


          else:
            check+=1
            if check==mini_lst and change==0:
              compare=0

              less=min(len(lst[i][0]),len(lst[i][1]))
              extra=abs(len(lst[i][0])-len(lst[i][1]))

              for k in range(less):
                compare=compare+(int(ord(lst[i][0][k])-int(ord(lst[i][1][k]))))

              final_lst.append(compare+extra)
              a=0
              break


file2=open("output.txt","w")
for val in final_lst:
    file2.write(str(val) + "\n")
file2.close()



