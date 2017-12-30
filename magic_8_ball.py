import random

class Magic_8_ball(object):

    #constructers
    def __init__(self):
        self.choices=["Yes,Absolutely!","Signs point to Yes!","Not Sure!","I dont think so!","Definitely not!"]

        self.reply=""    

    #Setters
    def shake(self):
        random_value=int(random.random()*len(self.choices))
        self.reply=self.choices[random_value]

    #Getters
    def getReply(self):
        return self.reply

def main():
    print("Welcome to magic ball game!!")
    my_8_ball=Magic_8_ball()

    while True:
        question=input("Enter a yes/no question:")

        my_8_ball.shake()
        print(my_8_ball.getReply())

        ch=input("Would you like to ask another ques:")
        if (ch[0].lower()=="n"):
            break

    print("Good Bye!!!!")
        
            
if __name__=="__main__":
    main()
