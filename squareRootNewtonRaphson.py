y=float(input("Enter the number:"))

epsilon =0.01
guess=y/2
numGuesses=0        


while(abs(guess*guess-y)>=epsilon):
        numGuesses=numGuesses+1
        guess=guess-(guess*guess-y)/(2*guess)

print("Number of guesses:",numGuesses)
print("Square root of number:",guess)        
        
