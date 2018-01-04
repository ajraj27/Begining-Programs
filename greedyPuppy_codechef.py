t=int(input())


while(t!=0):
	coins,people=map(int,input().split())
	max=0

	for i in range(people,0,-1):
		if(coins%i>max):
			max=coins%i

	print(max)		

	t=t-1			
