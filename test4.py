ctr=0
s="abcbobfdgboobsbob"

for i in range(len(s)-2):
    if(s[i:i+3]=="bob"):
        ctr=ctr+1
        
print("Number of times bob occurs is: "+str(ctr))       
    
