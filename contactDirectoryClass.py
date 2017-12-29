class Person(object):
    #Constructor
    def __init__(self,thename,thePhone,theEmail):
        self.name=thename
        self.Phone=thePhone
        self.Email=theEmail

    #Accesor methods(Getters)
    def getName(self):
         return self.name

    def getPhone(self):
         return self.Phone

    def getEmail(self):
         return self.Email

    #Mutator methods(Setters)
    def setPhone(self,newPhone):
            self.Email=newPhone

    def setEmail(self,newEmail):
         self.Email=newEmail

    def __str__(self):
        return "[Name="+self.name+" ,PhoneNo.="+str(self.Phone)+" ,EmailId="+self.Email+"]"

    def enter_a_friend():
        name=input("Enter a name:")
        phone=input("Enter a phone no:")
        email=input("Enter an email-id:")

        return Person(name,phone,email)

    def lookup_a_friend(friends):
        name=input("Enter a friend's name:")
        found=False           
        for friend in friends:
                   if name in friend.getName():
                       print(friend)
                       found=True
                       
        if not found:
                   print("No entry found")

    def show_all_friends(friends):
        print("Showing all friends:")                
        for friend in friends:
            print(friend)
                   
     
    
    

def main():
    friends=[]
    running=True

    while running:
        print("\nContacts MAnager:")                 
        print("(1)New Contact     (2)Lookup")
        print("(3)Show all        (4)End")

        choice=input(">")

        if(choice=="1"):
            friends.append(Person.enter_a_friend())

        elif(choice=="2"):
            Person.lookup_a_friend(friends)

        elif(choice=="3"):
            Person.show_all_friends(friends)

        elif(choice=="4"):
            running=False

        else:
            print("Wrong choice")

    print("Program Ends")            
            
    


if(__name__=="__main__"):
    main()
