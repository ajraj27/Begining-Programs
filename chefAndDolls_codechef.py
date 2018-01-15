t=int(input())

while(t!=0):
	n=int(input())
	dic={}

	for i in range(n):

		num=int(input())
		dic.setdefault(num,0)
		dic[num]+=1


	for val in list(dic.keys()):
		if(dic[val]%2!=0):
			print()
			break
	t=t-1			
