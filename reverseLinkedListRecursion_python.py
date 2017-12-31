class Node():

    def __init__(self,data):
        self.data=data
        self.next=None

    def getData(self):
        return self.data
    
    def getNext(self):
        return self.next

    def setData(self,newData):
        self.data=newData

    def setNext(self,newNext):
        self.next=newNext


class Linked_List():

    def __init__(self):
        self.head=None

    def getHead(self):
        return self.head

    def insert(self,data,n):
        temp=Node(data)

        if(n==1):
            temp.setNext(self.head)
            self.head=temp
            return

        current=self.head
        for i in range(n-2):
            current=current.getNext()

        temp.setNext(current.getNext())
        current.setNext(temp)

    def reverse(self,temp):

        if(temp.getNext()==None):
            self.head=temp
            return

        self.reverse(temp.getNext())
        temp1=temp.getNext()
        temp1.setNext(temp)
        temp.setNext(None)
        
             
            
            

    def print(self):
        current=self.head
        print("List is:",end="")
        while(current!=None):
            print(current.getData(),end=" ")
            current=current.getNext()

        print("\n")    


    

def main():
    myList=Linked_List()

    myList.insert(3,1)
    myList.print()
    myList.insert(5,2)
    myList.print()
    myList.insert(9,3)
    myList.print()
    myList.insert(11,2)
    myList.print()
    myList.insert(45,1)
    myList.print()

    myList.reverse(myList.getHead())
    myList.print()
          


if (__name__=="__main__"):
    main()
