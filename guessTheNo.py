print("Please think of a number between 0 and 100!")

low=0
high=100
mid=(low+high)//2
flag=0

while True:
    print("Is your secret number "+str(mid)+ "?")

    print("Enter 'h' to indicate the guess is too high. Enter 'l' to indicate the guess is too low. Enter 'c' to indicate I guessed correctly.")
    
    choice=input()

    if(choice=='c'):
        print("Game over.Your secret number was: ",mid)
        break

    elif(choice=='h'):
        high=mid
        
        if(flag==0):
            low=0
            flag=1
    
        
        mid=(high+low)//2
        

        
    elif(choice=='l'):
        low=mid
        if(flag==0):
            high=100
            flag=1
        
        
        mid=(high+low)//2
        

    else:
        print("Sorry, I did not understand your input.")
            
