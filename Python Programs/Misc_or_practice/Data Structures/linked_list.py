class Node: 
    def __init__(self, data): 
        self.data = data  
        self.next = None  
  
   
class LinkedList: 
    def __init__(self): 
        self.head = None

    def print(self):
        val=self.head
        while val!=None:
            print (val.data)
            val=val.next
    def prepend(self,node):
        temp=self.head
        self.head=node
        node.next=temp
    def append(self,node):
        term=self.head
        while term.next!=None:
            term=term.next
        term.next = node
    
    def insert(self,node,loc):
        count=0
        val=self.head
        while count!=loc-1:
            val=val.next
            count+=1
        term=self.head
        count2=0
        while count2!=loc:
            term=term.next
            count2+=1
        val.next=node
        node.next = term
    def reverse(self):
        val=self.head
        prev=None   
        while val!=None:
            p=prev
            prev=val
            temp=val.next
            val.next=p
            val=temp
            if val!= None and val.next==None:
                self.head=val
    def delete(self,node):
        val=self.head
        prev=None
        while val.data!=node.data:
            prev=val
            val=val.next
        n=val.next
        val=prev
        val.next=n
    def swap(self,n1,n2):
        val=self.head
        while val.next.data!=n1.data:
            val=val.next
        val2=self.head
        while val2.next.data!=n2.data:
            val2=val2.next
        val2.next=n1
        val.next=n2
        a=n1.next
        a2=n2.next
        
        n1.next=a2
        n2.next=a
        print (n1.data,n2.data,a)
        
        
    #def sort(self):
        
                
llist = LinkedList() 

llist.head = Node(1)
second = Node(2)
third=Node(3)
llist.head.next=second
second.next=third
llist.append(Node(4))
llist.print()

llist.swap(Node(2),Node(4))
llist.print()
