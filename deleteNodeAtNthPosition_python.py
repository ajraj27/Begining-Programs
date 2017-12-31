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

    def delete(self,n):

        current=self.head

        if(n==1):
            self.head=self.head.getNext()
            current.setNext(None)

        for i in range(n-2):
            current=current.getNext()

        temp1=current.getNext()
        current.setNext(temp1.getNext())
        temp1.setNext(None)
            
            

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
    myList.delete(3)
    myList.print()
    myList.insert(56,2)
    myList.print()
    myList.delete(4)
    myList.print()
    
          


if (__name__=="__main__"):
    main()
