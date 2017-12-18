def isIn(char,astr):
    num=len(astr)

    if(char==astr[num//2] or num==1):
        if(char==astr[num//2]):
            return True
        else:
            return False

    elif(char>astr[num//2]):
         return isIn(char,astr[num//2:])
        
    else:
        return  isIn(char,astr[:num//2])


char=input("Input the character:")
astr=input("Input the string in alphabetical order:")

boole=isIn(char,astr)
print(boole)
