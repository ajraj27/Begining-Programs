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

def isOpeningParanthesis(c):
    if(c=='(' or c=='{' or c=='['):
        return True
    else:
        return False

def isClosedParanthesis(c):
    if(c==')' or c=='}' or c==']'):
        return True
    else:
        return False

def arePair(c1,c2):
    if((c1=='(' and c2==')') or (c1=='{' and c2=='}') or (c1=='[' and c2==']')):
        return True
    else:
        return False
    

def checkBalancedParanthesis(a):
    
    s=Stack()
    for i in range(len(a)):

        if(isOpeningParanthesis(a[i])):
            s.push(a[i])

        elif(isClosedParanthesis(a[i])):
             if(s.isEmpty() or not arePair(s.top(),a[i])):
                 return False
                 

             else:
                 s.pop()

    if(s.isEmpty()):
        return True


a=input("Enter the paranthesis expression:")
print(checkBalancedParanthesis(a))
            









