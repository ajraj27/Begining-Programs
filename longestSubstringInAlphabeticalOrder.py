s=input("Enter the String:")
t=s+'A'


max=0
min=0
for i in range(len(s)):
    for j in range(i,len(s)):
        if(t[j]>t[j+1]):
                break
       
    if(j-i>max-min):
         max=j
         min=i

if(min==max):
    print("Longest subsring in alphabetical order is: ",t[0])
    
else:
    print("Longest subsring in alphabetical order is: ",t[min:max+1])         
