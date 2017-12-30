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

    def insert(self,data):
        temp=Node(data)

        if(self.head==None):
            self.head=temp
            return

        current=self.head    

        while((current.getNext())!=None):
            current=current.getNext()

        current.setNext(temp)    

    def print(self):
        current=self.head

        while(current!=None):
            print(current.getData(),end=" ")
            current=current.getNext()

        print("\n")    


    

def main():
    myList=Linked_List()
    n=int(input("Enter the no. of integers to enter:"))

    for i in range(n):
        x=int(input("Enter the integer:"))
        myList.insert(x)
        myList.print()
          


if (__name__=="__main__"):
    main()
