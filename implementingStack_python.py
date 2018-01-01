class Stack():

    def __init__(self):
        self.items=[]

    def isEmpty(self):
         return self.items==[]

    def push(self,data):
         self.items.append(data)

    def pop(self):
         return self.items.pop()

    def top(self):
        return self.items[len(self.items)-1]

    def size(self):
        return len(self.items)

myStack=Stack()
myStack.push(4)
myStack.push(6)
myStack.push(67)
print(myStack.top())
myStack.pop()
print(myStack.size())
print(myStack.isEmpty())
