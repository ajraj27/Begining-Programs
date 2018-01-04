t=int(input())


while(t!=0):
	a,b,c=map(int,input().split())

	if(abs(a-b)<=c):
		print(0)

	else:
		print(abs(abs(a-b)-c))	

	t=t-1			
