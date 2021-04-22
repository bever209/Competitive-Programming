def BaseChecker(num,target):
    #Checks other bases
    if str(bin(num))in str(target) or str(bin(target)) in str(num):
        print("binary")
    if str(oct(num))in str(target) or str(oct(target)) in str(num):
        print("octal")
    if str(hex(num))in str(target) or str(hex(target)) in str(num):
        print("hex")

###########################################################################################################################################################################################

def PowerChecker(num,target):
    # Checks different powers
    #Checks first 10 powers for now, change depending on size of the number
    for i in range(10):
        string=str(num**i)
        arr=list(string)
        if str(target) in string:
            print ("Power "+str(i)+" is useful, the target is a consecutive series of numbers")
    for i in range(2,20):
        if num**(1/i)==target:
            if num2**(1/i)==target2:
                print("This root works for both",i)
            else:
                print("This root works for only the first one")
    #I want to add more here
            

###########################################################################################################################################################################################
         
def ModChecker(num,target,num2,target2):
        #Checks Mods
    for i in range(1,100000):
        if num%i==target:
            if num2%i==target2:
                print("Type 1, modulus for both: ",i)
       
    for i in range(max(target,target2)):
        if num%target==i:
            if num2%target2==i:
                print ("Type 2, congruent for both: ",i)
           
    for i in range(max(num,num2)):
        if target%num==i:
            if target2%num2==i:
                print ("Type 3, congruent for both: ",i)
           
    for i in range(1,100000):
        if target%i==num:
            if target2%i==num2:
                print("Type 4, modulus for both: ",i)
       
###########################################################################################################################################################################################

def BasicArithChecker(num,target,num2,target2):
    if num*target==num2*target2:
        print ("Products are equal")
    if num/target==num2/target2:
        print ("Differences are equal")
    if num+target==num2+target2:
        print ("Sums are equal")
    if num-target==num2-target2:
        print ("Differences are equal")

###########################################################################################################################################################################################

def BasicStuffChecker(num,target,num2,target2):
    k1=str(num)
    v1=str(target)
    k2=str(num2)
    v2=str(target2)

    if k1 in v1 and k2 in v2:
        # Key is inside the value
        print ("Key is inside the value (num is inside target)")
        
    if v1 in k1 and v2 in k2:
        # Value is inside key
        print ("Value is inside the key (target is inside the num)")

###########################################################################################################################################################################################

def SumFold(num,spacing):
    #Finds the sum of the value formed by breaking num into numbers of size with spacing except for the final number
    string=""
    for i in range(len(str(num))):
        if i>len(str(num)):
            break
        try:
            string=string+str(int(str(num)[i:i+spacing]))+"+"
        except:
            string=string+str(int(str(num)[i:]))
            
    if string[-1]=="+":
        string=string[:-1]
    return eval(string)

    
def FoldingChecker(num,target,num2,target2):
    #Folding stuff
    #Need to code for when the length of the spacing is the same but when the targets have different length because of leading 0's
    if SumFold(num,len(str(target)))==SumFold(num2,len(str(target2))):
        print ("Match with folding with the key")
    if SumFold(num**2,len(str(target)))==SumFold(num2**2,len(str(target2))):
        print ("Match with folding by squaring the key")

    if SumFold(target,len(str(num)))==SumFold(target2,len(str(num2))):
        print ("Match with folding with the value")
    if SumFold(target**2,len(str(num)))==SumFold(target2**2,len(str(num2))):
        print ("Match with folding by squaring the value")
    
    
    
    
                

###########################################################################################################################################################################################

def HashChecker(num,target,num2=1,target2=1):
    if num2==1 and target2==1:
        print ("Beware, you did not enter a second key, value pair")
    BaseChecker(num,target)

    PowerChecker(num,target)
    
    ModChecker(num,target,num2,target2)
    
    BasicArithChecker(num,target,num2,target2)

    BasicStuffChecker(num,target,num2,target2)

    FoldingChecker(num,target,num2,target2)



###########################################################################################################################################################################################
num1=input("Enter first key: ")
target1=input("Enter first value: ")
num2 = input("Enter second key (type pass if you don't want): ")
target2=input("Enter second value (type pass if you don't want): ")

if num2.lower()=="pass":
    HashChecker(int(num1),int(target1),1,1)

else:
    HashChecker(int(num1),int(target1),int(num2),int(target2))

