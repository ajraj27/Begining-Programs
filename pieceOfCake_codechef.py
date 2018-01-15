t=int(input())

while(t!=0):
	sum=0
	a=input()
	count={}

	for ch in a:
		count.setdefault(ch,0)
		count[ch]+=1

	myList=list(sorted(zip(count.values(),count.keys())))
	rem=myList.pop()
	 
	for v,k in myList :
		sum=sum+v

	if(sum==rem[0]):
		print("YES")

	else:
		print("NO")	

	t=t-1			    
		  
