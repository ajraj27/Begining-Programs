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

            
     
    
    

def main():
    friend1=Person("Anuj",9939753572,"anujthechamp100@gmail.com")
    print(friend1.getEmail())
    friend1.setEmail("rajanuj.iiita@gmail.com")
    print(friend1.getEmail())
    print(friend1)
    


if(__name__=="__main__"):
    main()
