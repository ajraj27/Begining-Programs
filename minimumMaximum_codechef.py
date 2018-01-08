t=int(input())


while(t!=0):
	n=int(input())
	a=list(map(int,input().split()))
	size=len(a)
	a.sort()
	

	print(a[0]*(size-1))		

	t=t-1			
