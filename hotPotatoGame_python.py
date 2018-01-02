from collections import deque
import random

def hot_potato(names,n):

    myList=deque(names)

    while(len(myList)>1):
        for i in range(n):
            myList.appendleft(myList.pop())

        myList.pop()

    return myList.pop()   


names=list(input().split())
n=random.randrange(5,20)
print(hot_potato(names,n))
