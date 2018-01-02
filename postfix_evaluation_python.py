from collections import deque

def isoperator(c):

    if(c=='+' or c=='-'or c=='*' or c=='/'):
        return True
    else:
        return False

def evaluate(c,op1,op2):

    if(c=='+'):
        return op1+op2
    elif(c=='-'):
        return op1-op2
    elif(c=='*'):
        return op1*op2
    else:
        return op1/op2
    

def postfix_evaluation(exp):
    s=deque()
    i=0
    while(i<len(exp)):

        if(exp[i]==','):
            i=i+1
            continue

        elif(exp[i].isdigit()):
            operand=0

            while(i<len(exp) and exp[i].isdigit()):
                operand=operand*10+int(exp[i])
                i=i+1

            i=i-1
            s.append(operand)

        elif(isoperator(exp[i])):
              op2=s.pop()
              op1=s.pop()
              res=evaluate(exp[i],op1,op2)
              s.append(res)

        else:
              print("Invalid Input")
              return

        i=i+1    

               
    return s.pop()


exp=input("Enter the postfix expression:")
print(postfix_evaluation(exp))              
        
