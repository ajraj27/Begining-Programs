import math
t=int(input())

while(t!=0):
    n=int(input())
    choice='yes'

    for i in range(2,int(math.sqrt(n))+1):
        if(n%i==0):
            choice='no'
            break

    print(choice)        
    t=t-1        

    
