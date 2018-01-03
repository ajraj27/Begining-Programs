from stack import Stack

def isOperator(c):

    if(c=='+' or c=='-' or c=='*' or c=='/'):
        return True
    else:
        return False

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

def getOperatorWeight(c):

    weight={'+':1,'-':1,'*':2,'/':2}
    return weight[c]

def higherPrecedance(op1,op2):
    op1Weight=getOperatorWeight(op1)
    op2Weight=getOperatorWeight(op2)

    if(op1Weight>=op2Weight):
        return True
    else:
        return False
    

def infix_to_postfix(exp):
    s=Stack()
    post_exp=[]
    
    i=0
    while(i<len(exp)):

        if(exp[i].isdigit()):
            operand=0
            while(i<len(exp) and exp[i].isdigit()):
                operand=operand*10+int(exp[i])
                i=i+1

            post_exp.append(','+str(operand))
            i=i-1
            

        elif(isOperator(exp[i])):

             while(not s.isEmpty() and not isOpeningParanthesis(s.top()) and higherPrecedance(s.top(),exp[i])):
                   post_exp.append(s.top())
                   s.pop()

             s.push(exp[i])

        elif(isOpeningParanthesis(exp[i])):
             s.push(exp[i])

        elif(isClosedParanthesis(exp[i])):

             while(not s.isEmpty() and not isOpeningParanthesis(s.top())):
                   post_exp.append(s.top())
                   s.pop()

             s.pop()

        else:
             print("Invalid Input")
             return

        i=i+1    

    while(not s.isEmpty()):
        post_exp.append(s.top())
        s.pop()


    st=''.join(post_exp)
    print(st.lstrip(','))


exp=input("Enter the infix expression:")
infix_to_postfix(exp)                   
                   
